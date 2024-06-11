#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

void SaveHBITMAPToFile(HBITMAP hBitmap, const char* fileName);
PBITMAPINFO CreateBitmapInfoStruct(HBITMAP hBmp);
BITMAPFILEHEADER CreateBitmapFileHeader(PBITMAPINFO pbi);

int main() {
    // 获取屏幕截图
    HDC hdc = GetDC(0);
    HDC hdcMem = CreateCompatibleDC(hdc);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, screenWidth, screenHeight);
    SelectObject(hdcMem, hBitmap);
    BitBlt(hdcMem, 0, 0, screenWidth, screenHeight, hdc, 0, 0, SRCCOPY);

    // 保存截图到文件
    int fileNameLength = 15; // 根据需要调整文件名长度
    char fileName[fileNameLength];
    sprintf(fileName, "screenshot.bmp");
    SaveHBITMAPToFile(hBitmap, fileName);

    // 声明文件指针
    FILE* outputFile;

    // 打开文件，使用 "w" 模式创建或覆盖文件
    outputFile = fopen("output.txt", "w");

    if (!outputFile) {
        perror("Error opening file");
        return 1;
    }

    // 调用 Tesseract 进行 OCR
    char command[100];
    sprintf(command, "tesseract %s output -l eng", fileName);
    system(command);

    // 读取 OCR 结果
    char ocrResult[100];
    fgets(ocrResult, sizeof(ocrResult), outputFile);

    // 处理 OCR 结果，这里简单打印出来
    printf("OCR Result: %s\n", ocrResult);

    // 关闭文件
    fclose(outputFile);

    // 释放资源
    DeleteObject(hBitmap);
    DeleteDC(hdcMem);
    ReleaseDC(0, hdc);

    return 0;
}

void SaveHBITMAPToFile(HBITMAP hBitmap, const char* fileName) {
    PBITMAPINFO bitmapInfo;
    BITMAPFILEHEADER fileHeader;

    HDC hdc = GetDC(0);
    HDC hdcMem = CreateCompatibleDC(hdc);

    bitmapInfo = CreateBitmapInfoStruct(hBitmap);

    // 创建文件头
    fileHeader = CreateBitmapFileHeader(bitmapInfo);

    // 将文件头写入文件
    FILE* file = fopen(fileName, "wb");
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);

    // 将位图信息写入文件
    fwrite(bitmapInfo, bitmapInfo->bmiHeader.biSize, 1, file);

    // 将位图数据写入文件
    int bitmapSize = bitmapInfo->bmiHeader.biSizeImage;
    char* bitmapBits = (char*)malloc(bitmapSize);
    GetDIBits(hdcMem, hBitmap, 0, (UINT)bitmapInfo->bmiHeader.biHeight, bitmapBits, bitmapInfo, DIB_RGB_COLORS);
    fwrite(bitmapBits, 1, bitmapSize, file);

    fclose(file);
    free(bitmapBits);
    DeleteObject(hBitmap);
    DeleteDC(hdcMem);
    ReleaseDC(0, hdc);
}

PBITMAPINFO CreateBitmapInfoStruct(HBITMAP hBmp) {
    BITMAP bmp;
    PBITMAPINFO pbmi;
    WORD    cClrBits;

    // Retrieve the bitmap color format, width, and height.
    if (!GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp))
        printf("GetObject");

    // Convert the color format to a count of bits.
    cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel);
    if (cClrBits == 1)
        cClrBits = 1;
    else if (cClrBits <= 4)
        cClrBits = 4;
    else if (cClrBits <= 8)
        cClrBits = 8;
    else if (cClrBits <= 16)
        cClrBits = 16;
    else if (cClrBits <= 24)
        cClrBits = 24;
    else cClrBits = 32;

    // Allocate memory for the BITMAPINFO structure.
    if (cClrBits != 24)
        pbmi = (PBITMAPINFO)LocalAlloc(LPTR,
            sizeof(BITMAPINFOHEADER) +
            sizeof(RGBQUAD) * (1 << cClrBits));

    // There is no RGBQUAD array for the 24-bit-per-pixel format.
    else
        pbmi = (PBITMAPINFO)LocalAlloc(LPTR,
            sizeof(BITMAPINFOHEADER));

    // Initialize the fields in the BITMAPINFO structure.
    pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    pbmi->bmiHeader.biWidth = bmp.bmWidth;
    pbmi->bmiHeader.biHeight = bmp.bmHeight;
    pbmi->bmiHeader.biPlanes = bmp.bmPlanes;
    pbmi->bmiHeader.biBitCount = bmp.bmBitsPixel;
    if (cClrBits < 24)
        pbmi->bmiHeader.biClrUsed = (1 << cClrBits);

    // If the bitmap is not compressed, set the BI_RGB flag.
    pbmi->bmiHeader.biCompression = BI_RGB;

    // Compute the number of bytes in the array of color
    // indices and store the result in biSizeImage.
    pbmi->bmiHeader.biSizeImage = (pbmi->bmiHeader.biWidth + 7) / 8 *
        pbmi->bmiHeader.biHeight * cClrBits;

    // Set biClrImportant to 0, indicating that all of the
    // device colors are important.
    pbmi->bmiHeader.biClrImportant = 0;

    return pbmi;
}

BITMAPFILEHEADER CreateBitmapFileHeader(PBITMAPINFO pbi) {
    BITMAPFILEHEADER hdr;
    LPBYTE lpBits;
    DWORD dwTotal;
    // Size of the entire file
    dwTotal = sizeof(BITMAPFILEHEADER) + pbi->bmiHeader.biSize + pbi->bmiHeader.biClrUsed
        * sizeof(RGBQUAD) + pbi->bmiHeader.biSizeImage;
    hdr.bfType = 0x4d42;        // 0x42 = "B" 0x4d = "M"
    hdr.bfSize = dwTotal;       // Size of the entire file
    hdr.bfReserved1 = 0;        // Reserved
    hdr.bfReserved2 = 0;        // Reserved
    hdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + pbi->bmiHeader.biSize
        + pbi->bmiHeader.biClrUsed * sizeof(RGBQUAD);
    // Size of the bitmap info header + color table
    lpBits = (LPBYTE)LocalAlloc(LPTR, dwTotal);
    // Allocate memory for the bitmap bits
    if (!lpBits)
        printf("LocalAlloc");

    // Copy the bitmap file header into the memory
    memcpy(lpBits, &hdr, sizeof(BITMAPFILEHEADER));
    // Copy the bitmap info header and color table into the memory
    memcpy(lpBits + sizeof(BITMAPFILEHEADER), pbi,
        sizeof(BITMAPINFOHEADER) + pbi->bmiHeader.biClrUsed
        * sizeof(RGBQUAD));

    return hdr;
}

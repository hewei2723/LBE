#define cimg_display 0
#include "CImg.h"
#include <iostream>

using namespace cimg_library;

int main() {
	char inputFilePath[256];
	std::cout << "请输入源文件路径：";
	std::cin.getline(inputFilePath, 256);
	
	try {
		CImg<unsigned char> image(inputFilePath);
		std::FILE* rawFile = std::fopen("output.raw", "wb");
		if (rawFile == nullptr) {
			std::cerr << "无法打开输出RAW文件。" << std::endl;
			return 1;
		}
		
		cimg_forXY(image, x, y) {
			std::fputc(image(x, y, 0), rawFile); // R
			std::fputc(image(x, y, 1), rawFile); // G
			std::fputc(image(x, y, 2), rawFile); // B
		}
		
		std::fclose(rawFile);
		std::cout << "图像转换成功。Raw文件保存在当前文件夹下的 output.raw" << std::endl;
		
	} catch (CImgIOException& exception) {
		std::cerr << "CImg I/O 错误: " << exception.what() << std::endl;
		return 1;
	}
	
	return 0;
}


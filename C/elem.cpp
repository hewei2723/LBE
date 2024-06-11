Status Ilist(Sqlist &L)
{
    L.elem = New ElemType[maxsize]; // 分配一个最大长度为maxsize的数组空间
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
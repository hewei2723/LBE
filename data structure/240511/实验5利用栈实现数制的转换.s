	.file	"\312\265\321\3515\300\373\323\303\325\273\312\265\317\326\312\375\326\306\265\304\327\252\273\273.c"
 # GNU C17 (x86_64-posix-seh, Built by MinGW-Builds project) version 11.4.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.25-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=core2 -march=nocona -fno-asynchronous-unwind-tables -finput-charset=UTF-8 -fexec-charset=gbk
	.text
	.def	scanf;	.scl	3;	.type	32;	.endef
scanf:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	pushq	%rbx	 #
	subq	$56, %rsp	 #,
	movq	%rcx, 16(%rbp)	 # __format, __format
	movq	%rdx, 24(%rbp)	 #,
	movq	%r8, 32(%rbp)	 #,
	movq	%r9, 40(%rbp)	 #,
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:307:   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
	leaq	24(%rbp), %rax	 #, tmp86
	movq	%rax, -32(%rbp)	 # tmp86, MEM[(char * *)&__local_argv]
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:308:   __retval = __mingw_vfscanf( stdin, __format, __local_argv );
	movq	-32(%rbp), %rbx	 # __local_argv, __local_argv.3_1
	movl	$0, %ecx	 #,
	movq	__imp___acrt_iob_func(%rip), %rax	 #, tmp87
	call	*%rax	 # tmp87
	movq	%rbx, %r8	 # __local_argv.3_1,
	movq	16(%rbp), %rdx	 # __format,
	movq	%rax, %rcx	 # _2,
	call	__mingw_vfscanf	 #
	movl	%eax, -20(%rbp)	 # tmp88, __retval
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:310:   return __retval;
	movl	-20(%rbp), %eax	 # __retval, _10
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:311: }
	movq	-8(%rbp), %rbx	 #,
	leave	
	ret	
	.def	printf;	.scl	3;	.type	32;	.endef
printf:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	pushq	%rbx	 #
	subq	$56, %rsp	 #,
	movq	%rcx, 16(%rbp)	 # __format, __format
	movq	%rdx, 24(%rbp)	 #,
	movq	%r8, 32(%rbp)	 #,
	movq	%r9, 40(%rbp)	 #,
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:374:   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
	leaq	24(%rbp), %rax	 #, tmp86
	movq	%rax, -32(%rbp)	 # tmp86, MEM[(char * *)&__local_argv]
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:375:   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
	movq	-32(%rbp), %rbx	 # __local_argv, __local_argv.0_1
	movl	$1, %ecx	 #,
	movq	__imp___acrt_iob_func(%rip), %rax	 #, tmp87
	call	*%rax	 # tmp87
	movq	%rbx, %r8	 # __local_argv.0_1,
	movq	16(%rbp), %rdx	 # __format,
	movq	%rax, %rcx	 # _2,
	call	__mingw_vfprintf	 #
	movl	%eax, -20(%rbp)	 # tmp88, __retval
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:377:   return __retval;
	movl	-20(%rbp), %eax	 # __retval, _10
 # C:/Program Files/RedPanda-Cpp/MinGW64/x86_64-w64-mingw32/include/stdio.h:378: }
	movq	-8(%rbp), %rbx	 #,
	leave	
	ret	
	.globl	InitStack
	.def	InitStack;	.scl	2;	.type	32;	.endef
InitStack:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	movq	%rcx, 16(%rbp)	 # S, S
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:14: 	S->top = -1;
	movq	16(%rbp), %rax	 # S, tmp82
	movl	$-1, 400(%rax)	 #, S_2(D)->top
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:15: }
	nop	
	popq	%rbp	 #
	ret	
	.globl	StackEmpty
	.def	StackEmpty;	.scl	2;	.type	32;	.endef
StackEmpty:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	movq	%rcx, 16(%rbp)	 # S, S
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:18: 	return S->top == -1;
	movq	16(%rbp), %rax	 # S, tmp86
	movl	400(%rax), %eax	 # S_4(D)->top, _1
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:18: 	return S->top == -1;
	cmpl	$-1, %eax	 #, _1
	sete	%al	 #, _2
	movzbl	%al, %eax	 # _2, _5
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:19: }
	popq	%rbp	 #
	ret	
	.globl	StackFull
	.def	StackFull;	.scl	2;	.type	32;	.endef
StackFull:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	movq	%rcx, 16(%rbp)	 # S, S
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:22: 	return S->top == StackSize - 1;
	movq	16(%rbp), %rax	 # S, tmp86
	movl	400(%rax), %eax	 # S_4(D)->top, _1
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:22: 	return S->top == StackSize - 1;
	cmpl	$99, %eax	 #, _1
	sete	%al	 #, _2
	movzbl	%al, %eax	 # _2, _5
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:23: }
	popq	%rbp	 #
	ret	
	.section .rdata,"dr"
.LC0:
	.ascii "Stack is full.\12\0"
	.text
	.globl	Push
	.def	Push;	.scl	2;	.type	32;	.endef
Push:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	subq	$32, %rsp	 #,
	movq	%rcx, 16(%rbp)	 # S, S
	movl	%edx, 24(%rbp)	 # x, x
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:26: 	if (StackFull(S)) {
	movq	16(%rbp), %rcx	 # S,
	call	StackFull	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:26: 	if (StackFull(S)) {
	testl	%eax, %eax	 # _1
	je	.L11	 #,
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:27: 		printf("Stack is full.\n");
	leaq	.LC0(%rip), %rax	 #, tmp86
	movq	%rax, %rcx	 # tmp86,
	call	printf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:28: 		exit(EXIT_FAILURE); // æ ˆæ»¡ï¼Œæ— æ³•å…¥æ ˆï¼Œç¨‹åºé€€å‡º
	movl	$1, %ecx	 #,
	call	exit	 #
.L11:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:30: 		S->data[++(S->top)] = x; // å…ˆå°†æ ˆé¡¶æŒ‡é’ˆåŠ 1ï¼Œç„¶åå°†å…ƒç´ xå…¥æ ˆ
	movq	16(%rbp), %rax	 # S, tmp87
	movl	400(%rax), %eax	 # S_6(D)->top, _2
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:30: 		S->data[++(S->top)] = x; // å…ˆå°†æ ˆé¡¶æŒ‡é’ˆåŠ 1ï¼Œç„¶åå°†å…ƒç´ xå…¥æ ˆ
	leal	1(%rax), %edx	 #, _3
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:30: 		S->data[++(S->top)] = x; // å…ˆå°†æ ˆé¡¶æŒ‡é’ˆåŠ 1ï¼Œç„¶åå°†å…ƒç´ xå…¥æ ˆ
	movq	16(%rbp), %rax	 # S, tmp88
	movl	%edx, 400(%rax)	 # _3, S_6(D)->top
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:30: 		S->data[++(S->top)] = x; // å…ˆå°†æ ˆé¡¶æŒ‡é’ˆåŠ 1ï¼Œç„¶åå°†å…ƒç´ xå…¥æ ˆ
	movq	16(%rbp), %rax	 # S, tmp89
	movl	400(%rax), %eax	 # S_6(D)->top, _4
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:30: 		S->data[++(S->top)] = x; // å…ˆå°†æ ˆé¡¶æŒ‡é’ˆåŠ 1ï¼Œç„¶åå°†å…ƒç´ xå…¥æ ˆ
	movq	16(%rbp), %rdx	 # S, tmp90
	cltq
	movl	24(%rbp), %ecx	 # x, tmp92
	movl	%ecx, (%rdx,%rax,4)	 # tmp92, S_6(D)->data[_4]
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:32: }
	nop	
	leave	
	ret	
	.section .rdata,"dr"
.LC1:
	.ascii "Stack is empty.\12\0"
	.text
	.globl	Pop
	.def	Pop;	.scl	2;	.type	32;	.endef
Pop:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	subq	$32, %rsp	 #,
	movq	%rcx, 16(%rbp)	 # S, S
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:35: 	if (StackEmpty(S)) {
	movq	16(%rbp), %rcx	 # S,
	call	StackEmpty	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:35: 	if (StackEmpty(S)) {
	testl	%eax, %eax	 # _1
	je	.L13	 #,
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:36: 		printf("Stack is empty.\n");
	leaq	.LC1(%rip), %rax	 #, tmp87
	movq	%rax, %rcx	 # tmp87,
	call	printf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:37: 		exit(EXIT_FAILURE); // æ ˆç©ºï¼Œæ— æ³•å‡ºæ ˆï¼Œç¨‹åºé€€å‡º
	movl	$1, %ecx	 #,
	call	exit	 #
.L13:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:39: 		return S->data[(S->top)--]; // å…ˆå–æ ˆé¡¶å…ƒç´ ï¼Œå†å°†æ ˆé¡¶æŒ‡é’ˆå‡1
	movq	16(%rbp), %rax	 # S, tmp88
	movl	400(%rax), %eax	 # S_6(D)->top, _2
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:39: 		return S->data[(S->top)--]; // å…ˆå–æ ˆé¡¶å…ƒç´ ï¼Œå†å°†æ ˆé¡¶æŒ‡é’ˆå‡1
	leal	-1(%rax), %edx	 #, _4
	movq	16(%rbp), %rcx	 # S, tmp89
	movl	%edx, 400(%rcx)	 # _4, S_6(D)->top
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:39: 		return S->data[(S->top)--]; // å…ˆå–æ ˆé¡¶å…ƒç´ ï¼Œå†å°†æ ˆé¡¶æŒ‡é’ˆå‡1
	movq	16(%rbp), %rdx	 # S, tmp90
	cltq
	movl	(%rdx,%rax,4), %eax	 # S_6(D)->data[_3], _9
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:41: }
	leave	
	ret	
	.globl	StackTop
	.def	StackTop;	.scl	2;	.type	32;	.endef
StackTop:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	subq	$32, %rsp	 #,
	movq	%rcx, 16(%rbp)	 # S, S
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:44: 	if (StackEmpty(S)) {
	movq	16(%rbp), %rcx	 # S,
	call	StackEmpty	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:44: 	if (StackEmpty(S)) {
	testl	%eax, %eax	 # _1
	je	.L16	 #,
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:45: 		printf("Stack is empty.\n");
	leaq	.LC1(%rip), %rax	 #, tmp86
	movq	%rax, %rcx	 # tmp86,
	call	printf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:46: 		exit(EXIT_FAILURE); // æ ˆç©ºï¼Œæ— æ³•è·å–æ ˆé¡¶å…ƒç´ ï¼Œç¨‹åºé€€å‡º
	movl	$1, %ecx	 #,
	call	exit	 #
.L16:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:48: 	return S->data[S->top];
	movq	16(%rbp), %rax	 # S, tmp87
	movl	400(%rax), %eax	 # S_4(D)->top, _2
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:48: 	return S->data[S->top];
	movq	16(%rbp), %rdx	 # S, tmp88
	cltq
	movl	(%rdx,%rax,4), %eax	 # S_4(D)->data[_2], _6
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:49: }
	leave	
	ret	
	.section .rdata,"dr"
.LC2:
	.ascii "%d\327\252\273\273\316\252%d\275\370\326\306\312\375\316\252\243\272\0"
.LC3:
	.ascii "%d\0"
.LC4:
	.ascii "\12\0"
	.text
	.globl	MultiBaseOutput
	.def	MultiBaseOutput;	.scl	2;	.type	32;	.endef
MultiBaseOutput:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	andq	$-16, %rsp	 #,
	subq	$448, %rsp	 #,
	movl	%ecx, 16(%rbp)	 # N, N
	movl	%edx, 24(%rbp)	 # B, B
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:52: 	InitStack(&S);
	leaq	32(%rsp), %rax	 #, tmp85
	movq	%rax, %rcx	 # tmp85,
	call	InitStack	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:53: 	printf("%dè½¬æ¢ä¸º%dè¿›åˆ¶æ•°ä¸ºï¼š", N, B);
	movl	24(%rbp), %eax	 # B, tmp86
	movl	%eax, %r8d	 # tmp86,
	movl	16(%rbp), %edx	 # N,
	leaq	.LC2(%rip), %rax	 #, tmp87
	movq	%rax, %rcx	 # tmp87,
	call	printf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:54: 	while (N != 0) {
	jmp	.L19	 #
.L20:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:55: 		Push(&S, N % B); // å°†Né™¤ä»¥Bçš„ä½™æ•°å…¥æ ˆ
	movl	16(%rbp), %eax	 # N, tmp88
	cltd
	idivl	24(%rbp)	 # B
	leaq	32(%rsp), %rax	 #, tmp91
	movq	%rax, %rcx	 # tmp91,
	call	Push	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:56: 		N = N / B; // æ›´æ–°Nä¸ºNé™¤ä»¥Bçš„å•†
	movl	16(%rbp), %eax	 # N, tmp95
	cltd
	idivl	24(%rbp)	 # B
	movl	%eax, 16(%rbp)	 # tmp93, N
.L19:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:54: 	while (N != 0) {
	cmpl	$0, 16(%rbp)	 #, N
	jne	.L20	 #,
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:58: 	while (!StackEmpty(&S)) {
	jmp	.L21	 #
.L22:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:59: 		printf("%d", Pop(&S)); // ä¾æ¬¡å‡ºæ ˆå¹¶æ‰“å°ï¼Œå¾—åˆ°è½¬æ¢åçš„ç»“æœ
	leaq	32(%rsp), %rax	 #, tmp96
	movq	%rax, %rcx	 # tmp96,
	call	Pop	 #
	movl	%eax, %edx	 # _2,
	leaq	.LC3(%rip), %rax	 #, tmp97
	movq	%rax, %rcx	 # tmp97,
	call	printf	 #
.L21:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:58: 	while (!StackEmpty(&S)) {
	leaq	32(%rsp), %rax	 #, tmp98
	movq	%rax, %rcx	 # tmp98,
	call	StackEmpty	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:58: 	while (!StackEmpty(&S)) {
	testl	%eax, %eax	 # _3
	je	.L22	 #,
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:61: 	printf("\n");
	leaq	.LC4(%rip), %rax	 #, tmp99
	movq	%rax, %rcx	 # tmp99,
	call	printf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:62: }
	nop	
	leave	
	ret	
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC5:
	.ascii "\307\353\312\344\310\353\323\373\327\252\273\273\265\304\312\256\275\370\326\306\312\375\243\272\0"
.LC6:
	.ascii "\307\353\312\344\310\353\323\373\327\252\273\273\263\311\265\304\275\370\326\306\243\272\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	pushq	%rbp	 #
	movq	%rsp, %rbp	 #,
	subq	$48, %rsp	 #,
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:63: int main() {
	call	__main	 #
.L24:
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:66: 		printf("è¯·è¾“å…¥æ¬²è½¬æ¢çš„åè¿›åˆ¶æ•°ï¼š");
	leaq	.LC5(%rip), %rax	 #, tmp85
	movq	%rax, %rcx	 # tmp85,
	call	printf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:67: 		scanf("%d", &N);
	leaq	-4(%rbp), %rax	 #, tmp86
	movq	%rax, %rdx	 # tmp86,
	leaq	.LC3(%rip), %rax	 #, tmp87
	movq	%rax, %rcx	 # tmp87,
	call	scanf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:68: 		printf("è¯·è¾“å…¥æ¬²è½¬æ¢æˆçš„è¿›åˆ¶ï¼š");
	leaq	.LC6(%rip), %rax	 #, tmp88
	movq	%rax, %rcx	 # tmp88,
	call	printf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:69: 		scanf("%d", &B);
	leaq	-8(%rbp), %rax	 #, tmp89
	movq	%rax, %rdx	 # tmp89,
	leaq	.LC3(%rip), %rax	 #, tmp90
	movq	%rax, %rcx	 # tmp90,
	call	scanf	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:70: 		MultiBaseOutput(N, B);
	movl	-8(%rbp), %edx	 # B, B.1_1
	movl	-4(%rbp), %eax	 # N, N.2_2
	movl	%eax, %ecx	 # N.2_2,
	call	MultiBaseOutput	 #
 # C:/Users/Administrator/Desktop/lbe/data structure/240511/ÊµÑé5ÀûÓÃÕ»ÊµÏÖÊıÖÆµÄ×ª»».c:64: 	while (1) {
	jmp	.L24	 #
	.ident	"GCC: (x86_64-posix-seh, Built by MinGW-Builds project) 11.4.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef

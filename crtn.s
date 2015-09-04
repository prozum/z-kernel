.section .init
	/* gcc add crtend.o's .init here */
	popl %ebp
	ret

.section .fini
	/* gcc add crtend.o's .fini here */
	popl %ebp
	ret

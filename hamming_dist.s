.global hamming_dist


hamming_dist:
    push %rbp
    movq %rsp,%rbp
    pxor  %xmm0,%xmm0
    pxor  %xmm1,%xmm1
    pxor  %xmm2,%xmm2
    movdqu (%rsi), %xmm1
    movdqu (%rdi), %xmm2
    xor %r8,%r8
    xor %r9,%r9
    movq $256,%r9
    .loop:
    pcmpistrm  $0x48, %xmm1, %xmm2
    xor %rcx,%rcx
    pmovmskb %xmm0,%rcx
    popcnt %rcx,%rcx
    subq %rcx,%r9
    addq $1,%r8
    movq %r8, %rcx
    salq $4, %rcx
    movq $0, %r10
    movb $0, %al
    clear_args:
    cmpq $16, %r10
    jge end_of_clear
    movb %al, (%rsi, %r10, 1)
    movb %al, (%rdi, %r10, 1)
    addq $1,%r10
    jmp clear_args
    end_of_clear:
    addq $16,%rdi
    addq $16,%rsi
    movdqu (%rsi), %xmm1
    movdqu (%rdi), %xmm2
    cmpq $15,%r8
    jle .loop
    xor %rax,%rax
    movq  %r9, %rax
    xorq %rdi,%rdi
    xorq %rsi,%rsi
    movq %rbp,%rsp
    pop %rbp
    ret
    
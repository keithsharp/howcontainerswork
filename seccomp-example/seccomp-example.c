#include <stdio.h>
#include <unistd.h>
#include <seccomp.h>

/*
 * To compile:
 *		gcc -o seccomp-example seccomp-example.c -lseccomp
 *
 * To run:
 *		sudo ./seccomp-example
 */

int main() {

    printf("Setting up the seccomp filter\n");
    scmp_filter_ctx ctx;
    ctx = seccomp_init(SCMP_ACT_KILL); // default action: kill

    // Basics we need to do anything at all
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);

    // Only allow dup to redirect stdout to stderr
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup2), 2,
                        SCMP_A0(SCMP_CMP_EQ, 1),
                        SCMP_A1(SCMP_CMP_EQ, 2));

    seccomp_load(ctx);

    // Redirect stderr to stdout
    printf("Redirecting stdout to stderr, this should work!\n");
    dup2(1, 2);
    printf("Redirecting stdout to stderr worked!\n");

    // Duplicate stderr to arbitrary fd
    printf("Redirecting stderr to a different FD, this should fail!\n");
    dup2(2, 42);
    printf("YOU SHOULD NOT SEE ME!!\n");

    return 0;
}

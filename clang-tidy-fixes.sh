clang-tidy "$1.cpp" "$2.h" -fix-errors \
-checks=*,-llvmlibc-implementation-in-namespace,-cppcoreguidelines-avoid-magic-numbers,\
-readability-magic-numbers,-modernize-use-trailing-return-type,-llvmlibc-callee-namespace,\
-altera-unroll-loops,-altera-id-dependent-backward-branch,-llvmlibc-restrict-system-libc-headers,\
-fuchsia-default-arguments-calls,-readability-identifier-length
savedcmd_hello_t490.mod := printf '%s\n'   hello_t490.o | awk '!x[$$0]++ { print("./"$$0) }' > hello_t490.mod

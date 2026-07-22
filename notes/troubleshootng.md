# Troubleshooting

## Error: Makefile:4: *** missing separator. Stop.

### Cause
The command lines under `all:` and `clean:` in the Makefile were indented with spaces instead of tabs.

### Fix
I deleted the spaces and replaced them with tabs.

### Lesson
In a Makefile, command lines under a target must begin with a tab character.

---

## Warning: loading out-of-tree module taints kernel

### Cause
My kernel module was built outside the main Linux kernel source tree.

### Meaning
This is expected for a beginner external module and does not mean the module failed.

---

## Warning: module verification failed: signature and/or required key missing

### Cause
My custom module is unsigned.

### Meaning
This is expected for a local test module and does not stop it from loading in this setup.

---

## Useful commands
```bash
make
make clean
sudo insmod hello_t490.ko
sudo rmmod hello_t490
dmesg | tail -n 20
ls
```

---

## Error: expected ')' before string constant

### Cause
There was a syntax problem around the `MODULE_PARM_DESC(...)` line.

### Meaning
Even a tiny formatting or punctuation mistake in a kernel macro can break the build.

### Fix
I replaced the affected lines with a clean known-good version of the parameter code and rebuilt the module.

### Lesson
When C macro code looks correct but still fails, it is often best to replace teh whole block instead of trying to guess at teh hidden formatting issues.


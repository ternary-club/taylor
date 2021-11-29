build:
	@echo ==== building =========================
	gcc -pedantic -s -O2 \
	-nostdlib \
	-fno-asynchronous-unwind-tables \
	-fdata-sections \
	-Wl,--gc-sections \
	-Wa,--noexecstack \
	-fno-builtin \
	-fno-stack-protector \
	-static \
	./src/main.s ./src/main.c \
	-o taylor \
	\
	&& strip -R .comment taylor
	exit

build-run:
	make build
	@echo ==== running ==========================
	@./taylor ./exec.ter
OBJECTS = boot.o kmain.o terminal.o
CC = i686-elf-gcc
CFLAGS = -c -std=gnu11 -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -ffreestanding -O2 -nostdlib -lgcc
AS = i686-elf-as
ASFLAGS =

all: kernel.elf

kernel.elf: $(OBJECTS)
	$(CC) -T linker.ld -o kernel.elf $(LDFLAGS) $(OBJECTS)

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
	            -b boot/grub/stage2_eltorito    \
	            -no-emul-boot                   \
	            -boot-load-size 4               \
	            -A os                           \
	            -input-charset utf8             \
	            -quiet                          \
	            -boot-info-table                \
	            -o os.iso                       \
	            iso

run: os.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso

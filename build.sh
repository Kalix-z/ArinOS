make
make

sudo mount filesystem.img C
sudo cp osFiles/bin/* C/SlavOS
sudo umount C

sudo dd if=bin/kernel.bin of=bin/image.img
mv -f bin/image.img iso/boot/image.img
grub-mkrescue -o bin/bootable.iso iso
sudo fallocate -l 10485760 bin/bootable.iso -x
echo "here"
cat bin/bootable.iso filesystem.img > boot.img
echo "here2"
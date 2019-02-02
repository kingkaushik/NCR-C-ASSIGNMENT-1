#include<stdio.h>
#include<conio.h>

int set_bits_counter_of_last_four_bits(int);
int byte_order_reverser(int);
int bits_counter(int);
int rotate_four_bits(int);

int main()
{
	int val = 0xCAFE;

	//(a) TESTING IF ATLEAST THREE OF LAST FOUR BITS ARE ON
	int set_bits_count_of_last_four_bits = set_bits_counter_of_last_four_bits(val);
	if (set_bits_count_of_last_four_bits >= 3)
	{
		printf("ATLEAST THREE OUT OF LAST FOUR BITS ARE SET\n");
	}
	else
	{
		printf("ATLEAST THREE OUT OF LAST FOUR BITS ARE NOT SET\n");
	}
	printf("THE NUMBER OF BITS SET OF LAST FOUR BITS = %d\n",set_bits_count_of_last_four_bits);
	
	//(b) REVERSE THE BYTE ORDER(i.e PRODUCE val=0xFECA)
	int reversed_byte_order = byte_order_reverser(val);
	if (reversed_byte_order != 0)
		printf("THE REVERSED BYTE ORDER OF %#X = %#X\n", val, reversed_byte_order);
	else
		printf("THE VALUE %d IS LESS THAN A BYTE\n",val);

	//(c) ROTATE FOURBITS(i.e PRODUCE val=0xECAF)
	int four_bits_rotated_number = rotate_four_bits(val);
	if (four_bits_rotated_number != 0)
		printf("AFTER ROTATION OF FOUR BITS OF %#X THE NEW VALUE = %#X\n",val,four_bits_rotated_number);

	_getch();
	return 0;
}

int set_bits_counter_of_last_four_bits(int val)
{
	int set_bits_count = 0;
	for (int bit = 0; bit < 4; bit++)
	{
		int remainder = val % 2;
		if (remainder && 1)
			set_bits_count++;
		val /= 2;
	}
	return set_bits_count;
}

int bits_counter(int val)
{
	int no_of_bits = 0;
	while (val)
	{
		no_of_bits++;
		val /= 2;
	}
	return no_of_bits;
}

int byte_order_reverser(int val)
{
	int byte_val = 255;
	int no_of_bits = bits_counter(val);
	int no_of_bytes = no_of_bits / 8;
	int reversed_byte_order = 0;
	for (int byte = 1; byte <= no_of_bytes; byte++)
	{
		reversed_byte_order += ((val & byte_val)>>(8*(byte-1)));
		byte_val <<= 8;
		reversed_byte_order <<= 8;
	}
	reversed_byte_order >>= 8;
	return reversed_byte_order;
}

int rotate_four_bits(int val)
{
	int no_of_bits = bits_counter(val);
	if (no_of_bits < 4)
		return 0;
	int last_four_bits = val & 15;
	int val_except_last_four_bits = val >> 4;
	int four_bits_reversed_number = (last_four_bits<<(no_of_bits-4))+val_except_last_four_bits;
	return four_bits_reversed_number;
}
#define _CRT_SECURE_NO_WARNINGS 1
int move(int* nums,int numSize,int val)
{
	int src = 0, dst = 0;
	while (src < numSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			
			src++;
		}
	}
	return dst;
}
int main()
{
	int* nums[] = { 1,5,6,5,9,4,5 };
	move(nums, 7, 5);
	return 0;
}
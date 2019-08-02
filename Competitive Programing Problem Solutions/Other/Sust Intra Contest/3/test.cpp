#include <stdio.h>

int main() {
		int testCases, lengthOfNumber,index;
		char array;
		long long counter;
		scanf("%d",&testCases);

		for(;testCases;testCases--)
		{
			counter=0;
			scanf("%d",&lengthOfNumber);
			getchar();
			for(index=0;index<lengthOfNumber;index++)
			{
				scanf("%c",&array);
				if(array=='1')
				{
					counter++;
				}
			}

			printf("%lld\n",counter*(counter+1)/2);
		}


	return 0;
}

package chap1;

public class chap1_1_binarySearch 
{
	public static int binarySearch(int []a,int x,int n)
	{
		int left=0;int right=n-1;
		while(left<=right)
		{
			int middle=(left+right)/2;
			if(x==a[middle]) return middle;
			if(x>a[middle]) left=middle+1;
			else right=middle-1;
		}
		return -1;
	}
	
	public static void main(String[] args)
	{
		int []a= {0,1,2,3,4,5,6,7,8,9};
		int x=7;int n=10;
		System.out.println(binarySearch(a,x,n));
	}
}

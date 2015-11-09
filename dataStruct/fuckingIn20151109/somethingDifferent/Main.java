import java.util.*;
public class Main{
	public static void main(String[] args)
	{
		int[] arr = new int[100];
		Random rnd = new Random();
		for(int i=0;i<100;i++)
			arr[i]=rnd.nextInt(500);
		QSort qs = new QSort(arr);
		int[] sorted = qs.getSort();
		int i = 1;
		System.out.println("this is no sort date");
		for(int j:arr)
		{
			System.out.print(j+"\t");
			i++;
			if(i%11==0)
			{
				System.out.println();
				i=1;
			}
		}
		i=1;
		System.out.println("this is the Sorted date");
		for(int j:sorted)
		{
			System.out.print(j+"\t");
			i++;
			if(i%11==0)
			{
				System.out.println();
				i=1;
			}
		}
	}
}

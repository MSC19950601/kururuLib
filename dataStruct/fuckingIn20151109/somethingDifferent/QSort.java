import java.util.*;
public class QSort{
	//this number is the wait to sort Array 
	private int[] arrNum;
	//Init the arrNum;
	public QSort(int[] Arr)
	{
		this.arrNum = Arr;
	}
	//to set the arr
	public void setArr(int[] Arr)
	{
		this.arrNum = Arr;
	}
	//to return the arr
	public int[] getArr()
	{
		return this.arrNum;
	}
	//start to sort
	private List<Integer>  sort(List<Integer> arr)
	{
		//first,we need two array
		//the array's length is
		//the input arr's 1/2
		//one is <= input arr's first eml
		//other is >
		if(arr == null)
			return null;
		if(arr.size() <= 1 )
			return arr;
		List<Integer> lstA = new ArrayList<Integer>();
		List<Integer> lstB = new ArrayList<Integer>();
		//then we move the eml
		for(int i=1;i<arr.size();i++)
		{
			if(arr.get(i)<=arr.get(0))
				lstA.add(arr.get(i));
			else 
				lstB.add(arr.get(i));
		}
		List<Integer> Rtl = new ArrayList<Integer>();
		Rtl.addAll(this.sort(lstA));
		Rtl.add(arr.get(0));
		Rtl.addAll(this.sort(lstB));
		return Rtl;
	}

	public int[] getSort(){
		List<Integer> input = new ArrayList<Integer>();
		for(int i:this.arrNum)
			input.add(i);
		List<Integer> rt = this.sort(input);
		int[] rr = new int[rt.size()];
		for(int i=0;i<rt.size();i++)
			rr[i] = rt.get(i);
		return rr;
	}
}

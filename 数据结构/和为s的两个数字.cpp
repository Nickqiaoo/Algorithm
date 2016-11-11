class Solution{
public:
	vector<int> FindNumbersWithSum(vector<int> array,int sum){
		vector<int>num;
		int i=0,j=array.size()-1;
		while(i<j){
			if(array[i]+array[j]==sum){
				num.push_back(array[i]);
				num.push_back(array[j]);
				break;
			}
		while(i<j&&array[i]+array[j]>sum) --j;
		while(i<j&&array[i]+array[j]<sum) ++i;
		}
	return num;
	}
};


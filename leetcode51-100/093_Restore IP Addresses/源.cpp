#include<string>
#include<vector>

using namespace std;
class Solution {
public:

	bool isValid(string num){
		if (num.length() == 1 && num >= "0" && num <= "9")return true;
		if (num.length() == 2 && num >= "10" && num <= "99")return true;
		if (num.length() == 3 && num >= "100" && num <= "255")return true;
		return false;
	}

	void restoreIP(vector<string>&result, vector<string>&ips, int kth, int start, string s){
		if (start == s.length()){
			if (kth == 5){
				//�����ַ���
				string ip = ips[0];
				for (int i = 1; i<4; i++)
					ip += "." + ips[i];
				result.push_back(ip);
			}
			return;
		}

		//��s��startλ�ÿ�ʼȷ��ip���еĵ�kth����
		for (int k = 1; k <= 3 && start + (k - 1)<s.length(); k++){
			//��ǰ̽kλ����
			string num = s.substr(start, k);
			if (isValid(num)){
				ips.push_back(num);
				restoreIP(result, ips, kth + 1, start + k, s);
				ips.pop_back();
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.length()<4 || s.length()>12)return result; //ע���ַ�����Ч����

		vector<string>ips;
		restoreIP(result, ips, 1, 0, s);
		return result;
	}
};

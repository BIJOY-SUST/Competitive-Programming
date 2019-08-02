    #include<iostream>
    using namespace std;
    //to multiply first string with each character of 2nd string
    string multip(string s,char n){
    	string sr="";int sum=0,carry=0;
    	for(int i=s.length()-1;i>=0;i--){
    		sum=((s[i]-'0')*(n-'0'))+carry;//cout<<sum<<endl;
    		sr=char(sum%10+'0')+sr;
    		carry=sum/10;
    	}
    	while(carry){
    		sr=char(carry%10+'0')+sr;
    		carry/=10;
    	}
    	return sr;
    }
    //to put 0 at the end of any multiplication in place of X in elementary algo.
    string multiplyby(string s,int n){
    	int t=s.length();
    	for(int i=0;i<n;i++)
    	s+="0";
    	return s;
    }
    //to add to string
    string addon(string s1,string s2){
    	string s="";int sum=0,carry=0;
    	for(int i=s1.length()-1;i>=0;i--){
    		int sum=carry+s1[i]+s2[i]-'0'-'0';
    		int x=sum%10;char t=x+'0';
    		s=t+s;
    		carry=sum/10;
    	}
    	while(carry){
    		char v=carry%10+'0';
    		s=v+s;
    		carry/=10;
    	}
    	return s;
    }
    //main function to multily two string
    string m2(string s1,string s2){
    	int l=s1.length();
    	if(l<s2.length())
    	l=s2.length();
    	for(int i=s1.length();i<l;i++)
    	s1='0'+s1;
    	for(int i=s2.length();i<l;i++)
    	s2='0'+s2;
    	string s[l],sf;
    	for(int i=0;i<l;i++){
    		s[i]=multip(s1,s2[i]);
    		s[i]=multiplyby(s[i],l-i-1);
    		if(i>0){
    			for(int j=s[i-1].length();j<s[i].length();j++)
    			s[i-1]='0'+s[i-1];
    			for(int j=s[i].length();j<s[i-1].length();j++)
    			s[i]='0'+s[i];
    		}
    	}
    	for(int i=sf.length();i<s[0].length();i++)
    	sf='0'+sf;
    	for(int i=0;i<l;i++){
    		sf=addon(sf,s[i]);
    	}
    	bool flag=false;string srf="";
    	for(int i=0;i<sf.length();i++){
    		//to emit per zero of string
    		if(sf[i]=='0'&&flag==false&&i!=sf.length()-1)continue;
    		srf+=sf[i];
    		flag=true;
    	}
    	return srf;
    }
    int main(){
    	string s1,s2;cin>>s1>>s2;
    	cout<<m2(s1,s2);
    }

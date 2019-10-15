#include <iostream>
using namespace std;
int Pai[13],pai[13];
int tmpi,tmpj,sum=0;
int maxi=0,maxj=0;
int bottom[5],key1=0;
int middle[5],key2=0;
int up[3];

void out(int p,int n)
{
	if(n==1)
	{
		for(int j=0;j<13;j++)
		{
			if(pai[j]==p){
				pai[j]=0;break;
			} 
		}
	}else
	{
		if(p==13)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<13;j++)
				{
					if(pai[j]%13==0&&pai[j]!=0){
						pai[j]=0;break;
					} 
				}
			}
		}else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<13;j++)
				{
					if(pai[j]%13==p){
						pai[j]=0;break;
					} 
				}
			}
		}
	}
}

int ths()
{
	int num[53]={0};
	for(int i=0;i<13;i++) num[pai[i]]=1;	
	int flower,start,count=0,min=10,sig=0;//count经过对子数 
	
	int size[14]={0};
	for(int i=0;i<13;i++){
		if(pai[i]%13!=0) size[pai[i]%13]++;
		else size[13]++;
	}
	
	
	for(int i=0;i<=3;i++)
	if(num[1+i*13]==1&&num[10+i*13]==1&&num[11+i*13]==1&&num[12+i*13]==1&&num[13+i*13]==1){
		//cout<<10+i*13<<" "<<11+i*13<<" "<<12+i*13<<" "<<13+i*13<<" "<<1+i*13<<endl;
		//被抽出的牌,pai要减去 
		out(10+i*13,1);out(11+i*13,1);out(12+i*13,1);out(13+i*13,1);out(1+i*13,1);
		count=0;sig=1;
		if(size[1]>=2) count++;
		if(size[10]>=2) count++;
		if(size[11]>=2) count++;
		if(size[12]>=2) count++;
		if(size[13]>=2) count++;
		if(count<min) {
			min=count;start=10;flower=i;
		}
		if(key1==1){
			bottom[0]=10+i*13;bottom[1]=11+i*13;bottom[2]=12+i*13;bottom[3]=13+i*13;bottom[4]=1+i*13;
		} 
		if(key2==1){
			middle[0]=10+i*13;middle[1]=11+i*13;middle[2]=12+i*13;middle[3]=13+i*13;middle[4]=1+i*13;
		} 
		return 1;
	} 
	
	for(int i=13;i>=1;i--)
	for(int j=0;j<=3;j++)
	if(num[i+j*13]==1&&num[i+1+j*13]==1&&num[i+2+j*13]==1&&num[i+3+j*13]==1&&num[i+4+j*13]==1&&i+4<=13)
	{
		
		//cout<<i+j*13<<" "<<i+1+j*13<<" "<<i+2+j*13<<" "<<i+3+j*13<<" "<<i+4+j*13<<endl;
		//抽出的牌，pai减去 
		count=0;sig=1;
		if(size[i]>=2) count++;
		if(size[i+1]>=2) count++;
		if(size[i+2]>=2) count++;
		if(size[i+3]>=2) count++;
		if(size[i+4]>=2) count++;
		if(count<min) {
			min=count;start=i;flower=j;
		}
	}
	if(sig==1)
	{
		out(start+flower*13,1);out(start+1+flower*13,1);out(start+2+flower*13,1);out(start+3+flower*13,1);out(start+4+flower*13,1);
		//cout<<endl<<"找到以"<<start<<"开头的同花顺"<<endl;
		
		if(key1==1){
			bottom[0]=start+13*flower;bottom[1]=start+1+13*flower;bottom[2]=start+2+13*flower;bottom[3]=start+3+13*flower;bottom[4]=start+4+13*flower;
		} 
		if(key2==1){
			middle[0]=start+13*flower;middle[1]=start+1+13*flower;middle[2]=start+2+13*flower;middle[3]=start+3+13*flower;middle[4]=start+4+13*flower;
		} 
		
		return 1;
	}
	
	return 0;
}

int tz()
{
	int num[53]={0};
	for(int i=0;i<13;i++) num[pai[i]]=1;	
	for(int i=1;i<=13;i++)
	{
		if(num[i]==1&&num[i+13*1]==1&&num[i+13*2]==1&&num[i+13*3]==1)
		{
			//cout<<i<<" "<<i+13*1<<" "<<i+13*2<<" "<<i+13*3<<endl;
			if(key1==1){
				bottom[0]=i;bottom[1]=i+13;bottom[2]=i+26;bottom[3]=i+39;
			} 
			if(key2==1){
				middle[0]=i;middle[1]=i+13;middle[2]=i+26;middle[3]=i+39;
			}	 
			//更新pai 
			out(i,1);out(i+13*1,1);out(i+13*2,1);out(i+13*3,1);
			return 1; 
		}
	}
	return 0;
}

int hl()
{
	//先调用st,然后再查找一个任意的      对子(优先==2，若无，再>=2) 
	int size[14]={0};
	for(int i=0;i<13;i++){
		if(pai[i]%13==0&&pai[i]!=0)  size[13]++;
		else size[pai[i]%13]++;
	}
	
	int sig1=0,sig2=0;
	for(int i=14;i>=2;i--)
	{
		if(i==14) 
		{
			if(size[i%13]==3) {
				//cout<<"3个A"<<endl;
				size[1]-=3;
				if(key1==1){
					//for循环赋值A的具体花色值给bottom[0][1][2]
					int a=0;
					for(int j=0;j<13;j++)
					{
						if(pai[j]%13==1)
						{
							bottom[a++]=pai[j];
							pai[j]=0;
						}
					}
				} 
				if(key2==1){
					//for循环赋值A的具体花色值给bottom[0][1][2] 
					int a=0;
					for(int j=0;j<13;j++)
					{
						if(pai[j]%13==1)
						{
							middle[a++]=pai[j];
							pai[j]=0;
						}
					}
				} 
				sig1=1; out(1,3);break;
			}
		}else
		{
			if(size[i]==3){
				size[i]-=3;
				if(key1==1){
					//for循环赋值A的具体花色值给bottom[0][1][2] 
					
					if(i==13)
					{
						int a=0;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==0&&pai[j]!=0)
							{
								bottom[a++]=pai[j];
								pai[j]=0;
							}
						}
					}else
					{
						int a=0;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==i)
							{
								bottom[a++]=pai[j];
								pai[j]=0;
							}
						}
					}
					
				} 
				if(key2==1){
					//for循环赋值A的具体花色值给bottom[0][1][2] 
					
					if(i==13)
					{
						int a=0;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==0&&pai[j]!=0)
							{
								middle[a++]=pai[j];
								pai[j]=0;
							}
						}
					}else
					{
						int a=0;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==i)
							{
								middle[a++]=pai[j];
								pai[j]=0;
							}
						}
					}
					
					
				}
				
				sig1=1; out(i,3);break;
			}
		}
	}
	
	if(sig1==0)
	{
		for(int i=14;i>=2;i--)
		{
			if(i==14) 
			{
				if(size[i%13]>=3) {
					size[1]-=3;
					//cout<<"3个A"<<endl;
					if(key1==1){
					//for循环赋值A的具体花色值给bottom[0][1][2]
						int a=0;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==1)
							{
								bottom[a++]=pai[j];
								pai[j]=0;
								if(a==3) break;
							}
						}
					} 
					if(key2==1){
					//for循环赋值A的具体花色值给bottom[0][1][2] 
					
						int a=0;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==1)
							{
								middle[a++]=pai[j];
								pai[j]=0;
								if(a==3) break;
							}
						}
					}
					sig1=1; out(1,3);break;
				}
			}else
			{
				if(size[i]>=3){
					//cout<<"三个"<<i<<endl;
					size[i]-=3;
					if(key1==1){
					//for循环赋值A的具体花色值给bottom[0][1][2] 
						if(i==13)
						{
							int a=0;
							for(int j=0;j<13;j++)
							{
								if(pai[j]%13==0&&pai[j]!=0)
								{
									bottom[a++]=pai[j];
									pai[j]=0;
									if(a==3) break;
								}
							}
						}else
						{
							int a=0;
							for(int j=0;j<13;j++)
							{
								if(pai[j]%13==i)
								{
									bottom[a++]=pai[j];
									pai[j]=0;
									if(a==3) break;
								}
							}
						}
					} 
					if(key2==1){
					//for循环赋值A的具体花色值给bottom[0][1][2] 
						if(i==13)
						{
							int a=0;
							for(int j=0;j<13;j++)
							{
								if(pai[j]%13==0&&pai[j]!=0)
								{
									middle[a++]=pai[j];
									pai[j]=0;
									if(a==3) break;
								}
							}
						}else
						{
							int a=0;
							for(int j=0;j<13;j++)
							{
								if(pai[j]%13==i)
								{
									middle[a++]=pai[j];
									pai[j]=0;
									if(a==3) break;
								}
							}
						}
					}
					sig1=1;  out(i,3);break;
				}
			}
		}
	}
	
	if(sig1==0) return 0;
	
	for(int i=2;i<=14;i++)
	{
		if(i==14) 
		{
			if(size[i%13]==2) {
				//cout<<"2个A"<<endl;
				
				int a=3;
				for(int j=0;j<13;j++)
				{
					if(pai[j]%13==1)
					{
						if(key1==1)
						bottom[a++]=pai[j];
						if(key2==1)
						middle[a++]=pai[j];
						pai[j]=0;
						//if(a==2) break;
					}
				}
				
				sig2=1; out(1,2);break;
			}
		}else
		{
			if(size[i]==2){
				//cout<<"2个"<<i<<endl;
				if(i==13)
				{
					int a=3;
					for(int j=0;j<13;j++)
					{
						if(pai[j]%13==0&&pai[j]!=0)
						{
							if(key1==1)
							bottom[a++]=pai[j];
							if(key2==1)
							middle[a++]=pai[j];
							pai[j]=0;
							//if(a==3) break;
						}
					}
				}else
				{
					int a=3;
					for(int j=0;j<13;j++)
					{
						if(pai[j]%13==i)
						{
							if(key1==1)
							bottom[a++]=pai[j];
							if(key2==1)
							middle[a++]=pai[j];
							pai[j]=0;
							//if(a==3) break;
						}
					}
				}
				
				
				sig2=1; out(i,2);break;
			}
		}
	}
	
	if(sig2==0)
	{
		for(int i=2;i<=14;i++)
		{
			if(i==14) 
			{
				if(size[i%13]>=2) {
					//cout<<"2个A"<<endl;
					int a=3;
					for(int j=0;j<13;j++)
					{
						if(pai[j]%13==1)
						{
							if(key1==1)
							bottom[a++]=pai[j];
							if(key2==1)
							middle[a++]=pai[j];
							pai[j]=0;
							if(a==5) break;
						}
					}
					
					
					sig2=1; out(1,2);break;
				}
			}else
			{
				if(size[i]>=2){
					//cout<<"2个"<<i<<endl;
					if(i==13)
					{
						int a=3;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==0&&pai[j]!=0)
							{
								if(key1==1)
								bottom[a++]=pai[j];
								if(key2==1)
								middle[a++]=pai[j];
								pai[j]=0;
								if(a==5) break;
							}
						}
					}else
					{
						int a=3;
						for(int j=0;j<13;j++)
						{
							if(pai[j]%13==i)
							{
								if(key1==1)
								bottom[a++]=pai[j];
								if(key2==1)
								middle[a++]=pai[j];
								pai[j]=0;
								if(a==5) break;
							}
						}
					}
					sig2=1;  out(i,2);break;
				}
			}
		}
	}
	
	if(sig1*sig2==1) return 1;
	else return 0;
}


int th()
{
//	cout<<endl<<"查找同花前的牌:";
//	for(int k=0;k<13;k++) cout<<pai[k]<<" ";cout<<endl<<endl;
	
	int size[14]={0};
	for(int i=0;i<13;i++){
		if(pai[i]%13!=0) size[pai[i]%13]++;
		else size[13]++;
	}
	
	int num[53]={0};
	for(int i=0;i<13;i++) num[pai[i]]=1;
	
	int T=0,X=0,F=0,M=0;
	for(int i=0;i<13;i++)
	{
		if((pai[i]/13==0&&pai[i]!=0)||pai[i]==13) T++;
		else if(pai[i]/13==1||pai[i]==26) X++;
		else if(pai[i]/13==2||pai[i]==39) F++;
		else if(pai[i]/13==3||pai[i]==52) M++;
		else{
		}
	}
	if(T<5&&X<5&&F<5&&M<5) return 0;
	else
	{
		int flower;
		if(T>=5) flower=0;
		else if(X>=5) flower=1;
		else if(F>=5) flower=2;
		else flower=3;
		
		int count=0;//已经找到的合适的单张同花 
		
		
		if(num[1+flower*13]==1&&size[1]==1){
//			cout<<"最大单张同花:"<<1+flower*13<<endl;
			
			if(key1==1)
			bottom[count]=1+flower*13;
			if(key2==1)
			middle[count]=1+flower*13;
			count++;
			
			
			size[1+flower*13]--;num[1+flower*13]=0;
			for(int j=0;j<13;j++) if(pai[j]==1+flower*13){
						pai[j]=0;break;
					} 
			
		}else{
			for(int i=13+flower*13;i>=2+flower*13;i--)
			{
				if(i%13==0){
					if(num[i]==1&&size[13]==1)
					{
//						cout<<"最大单张同花:"<<i<<endl;
						
						if(key1==1)
						bottom[count]=i;
						if(key2==1)
						middle[count]=i;
						count++;
						
						size[13]--;num[i]=0;
						
						for(int j=0;j<13;j++) if(pai[j]==i){
							pai[j]=0;break;
						} 
						
						break;
					}	
				}else
				{
					if(num[i]==1&&size[i%13]==1)
					{
//						cout<<"最大单张同花:"<<i<<endl;
						if(key1==1)
						bottom[count]=i;
						if(key2==1)
						middle[count]=i;
						count++;
						
						
						size[i%13]--;num[i]=0;
						
						for(int j=0;j<13;j++) if(pai[j]==i){
							pai[j]=0;break;
						} 
						
						break;
					}
				}
				
				
			}
		}
		
		
		for(int i=2+flower*13;i<=12+flower*13;i++)
		{
			if(count==5) break;
			if(num[i]==1&&size[i%13]==1)
			{
				if(key1==1)
				bottom[count]=i;
				if(key2==1)
				middle[count]=i;
				count++;
				
				size[i%13]--;num[i]=0;   
				for(int j=0;j<13;j++) if(pai[j]==i){
						pai[j]=0;break;
					} 
			}
		}
		
		if(count==5) return 1;
		//特判13
		if(num[13+flower*13]==1&&size[13]==1)
		{
//			cout<<"较小的单张同花:"<<13+flower*13<<endl;
			if(key1==1)
			bottom[count]=13+flower*13;
			if(key2==1)
			middle[count]=13+flower*13;
			count++;
			
			size[13]--;num[13+13*flower]=0;   
			for(int j=0;j<13;j++) if(pai[j]==13+flower*13){
					pai[j]=0;break;
				} 
		}
		 
		
		
		
		for(int i=1+flower*13;i<=12+flower*13;i++)			//这里优先1，然后再优先小 
		{
			if(count==5) break;
			if(num[i]==1&&size[i%13]==2)
			{
//				cout<<"最小的非单张同花:"<<i<<endl;
				if(key1==1)
				bottom[count]=i;
				if(key2==1)
				middle[count]=i;
				count++;
										
				size[i%13]--;num[i]=0;   
				for(int j=0;j<13;j++) if(pai[j]==i){
						pai[j]=0;break;
					} 
				
			}
		}
		
		if(count==5)
		return 1;
		
		if(num[13+flower*13]==1&&size[13]==2)
		{
//			cout<<"最小的非单张同花:"<<13+flower*13<<endl;
			if(key1==1)
			bottom[count]=13+flower*13;
			if(key2==1)
			middle[count]=13+flower*13;
			count++;
			
			
			size[13]--;num[13+13*flower]=0; 
			for(int j=0;j<13;j++) if(pai[j]==13+flower*13){
					pai[j]=0;break;
				} 
		}
		
		
		
		if(count==5)
		return 1;	
		
		for(int i=1+flower*13;i<=12+flower*13;i++)			//这里优先1，然后再优先小 
		{
			if(count==5) break;
			if(num[i]==1&&size[i%13]>2)
			{
		//		cout<<"最小的非单张同花:"<<i<<endl;
				if(key1==1)
				bottom[count]=i;
				if(key2==1)
				middle[count]=i;
			 	count++;
				
								
				size[i%13]--;num[i]=0;   
				for(int j=0;j<13;j++) if(pai[j]==i){
						pai[j]=0;break;
					} 
				
			}
		}
		
		if(count==5)
		return 1;
		
		if(num[13+flower*13]==1&&size[13]>2)
		{
		//	cout<<"最小的非单张同花:"<<13+flower*13<<endl;
			if(key1==1)
			bottom[count]=13+flower*13;
			if(key2==1)
			middle[count]=13+flower*13;
			count++;
			
			size[13]--;num[13+13*flower]=0;   
			for(int j=0;j<13;j++) if(pai[j]==13+flower*13){
					pai[j]=0;break;
				} 
		}
		
		
		//cout<<endl<<"找出同花张数:"<<count<<endl;
		if(count==5)
		return 1;		
	}
}

int sz()
{
	int size[14]={0};
	for(int i=0;i<13;i++){
		if(pai[i]%13!=0) size[pai[i]%13]++;
		else if(pai[i]%13==0&&pai[i]!=0) size[13]++;
		else{
		}
	}
	
	int len=0,start=0,end=0,num=0;
	for(int i=13;i>=1;i--)
	{
		
		if(size[i]>=1){
			if(i==1) {
				start=1;len++;break;
			}else
			len++;
			
		} 
		else if(size[i]==0){
			if(len>=5){
				start=i+1;break;
			}
			else{
				len=0;continue;
			}
		}
	}
	
	

//	cout<<endl<<"检索出以"<<start<<"开头，长度为"<<len<<"的最长顺子"<<endl;
		
	if(len<=4){
		if(size[1]*size[10]*size[11]*size[12]*size[13]!=0){
//			cout<<"10-A对子"<<endl;
			
			//删掉牌中的一副10-A 
			for(int i=10;i<=14;i++)
			{
				if(i==14)
				{
					for(int j=0;j<13;j++)
					if(pai[j]%13==1){ 
					if(key1==1)
					bottom[4]=pai[j];
					if(key2==1)
					middle[4]=pai[j];
					
					pai[j]=0;break;
					}
				}else
				{
					for(int j=0;j<13;j++)
					if((pai[j]%13==i&&i!=13)||(pai[j]%13==0&&pai[j]!=0)){
					
					if(key1==1)
					bottom[i-10]=pai[j];
					if(key2==1)
					middle[i-10]=pai[j];
					
					pai[j]=0;break;
					}
				}
				
			}
			
			return 1;
			}
				else return 0;	
		}
	
	
	int min=10;//经过对子数 
	for(int i=start+len-1;i>=start+4;i--)
	{
		num=0;
		int j;
		if(i-4<1) break;
		for(j=i;j>=i-4;j--)
		if(size[j]>=2) num++;
		
		if(num<min)
		{
			 min=num;end=j+1;
		}
	}
	
	num=0;
	int signal0=0;
	if(size[1]*size[10]*size[11]*size[12]*size[13]!=0)
	{
		signal0=1;
		for(int i=10;i<=14;i++)
		{
			if(i==14){
				if(size[1]>=2) num++;
			}else{
				if(size[i]>=2) num++;
			}			
		}
	}
	
	if(num<=min&&signal0==1){
//		cout<<"10-A"<<endl;
		
		//删掉牌中的一副10-A 
			for(int i=10;i<=14;i++)
			{
				if(i==14)
				{
					for(int j=0;j<13;j++)
					if(pai[j]%13==1){ 
					if(key1==1)
					bottom[4]=pai[j];
					if(key2==1)
					middle[4]=pai[j];
					
					pai[j]=0;break;
					}
				}else if(i<=12)
				{
					for(int j=0;j<13;j++)
					if(pai[j]%13==i&&i!=13){
					
					if(key1==1)
					bottom[i-10]=pai[j];
					if(key2==1)
					middle[i-10]=pai[j];
					
					pai[j]=0;break;
					}
				}else
				{
					for(int j=0;j<13;j++)
					if(pai[j]%13==0&&pai[j]!=0){
					
					if(key1==1)
					bottom[i-10]=pai[j];
					if(key2==1)
					middle[i-10]=pai[j];
					
					pai[j]=0;break;
					}
					
				}
			}
	} 
	else{
//		cout<<endl<<"选出以"<<end<<"开始的顺子"<<endl; 
		
		
		
		//删掉牌中的顺子 
		int s=0;
		for(int i=end;i<=end+4;i++)
		{
			
			for(int j=0;j<13;j++)
			{
				if(i==13)
				{
					if(pai[j]%13==0&&pai[j]!=0){
					if(key1==1)
					bottom[s]=pai[j];
					if(key2==1)
					middle[s]=pai[j];
					pai[j]=0;
					s++;break;
						}
				}else
				{
					if(pai[j]%13==i){
					if(key1==1)
					bottom[s]=pai[j];
					if(key2==1)
					middle[s]=pai[j];
					pai[j]=0;
					s++;break;
						}
				}
			}
			
		}
		
//		cout<<"选出顺子后的牌：";
//		for(int k=0;k<13;k++) cout<<pai[k]<<" ";cout<<endl<<endl;
		
	}
	
	return 1;
}

int st()
{
	int size[14]={0};
	for(int i=0;i<13;i++){
		if(pai[i]%13==0&&pai[i]!=0) size[13]++;
		else size[pai[i]%13]++;
	} 
	int q=0;
	for(int i=1;i<=13;i++)  if(size[i]>=3){
		size[i]-=3;
		//删掉牌中的三条 
//		cout<<"三个"<<i<<endl;
		out(i,3);
		
		for(int k=0;k<13;k++)
		{
			if(pai[k]==0) continue;
			if(pai[k]%13==0){
				if(i==13){
					if(key1==1) 
					bottom[q]=pai[k];
					if(key2==1)
					middle[q]=pai[k];
					
					pai[k]=0;
					q++;
					if(q==3) break;
				}
			}
			else if(pai[k]%13==i)
			{
				if(key1==1) 
				bottom[q]=pai[k];
				if(key2==1)
				middle[q]=pai[k];
				
				pai[k]=0;
				q++;
				if(q==3) break;
			 } 
		}
		
		return 1;
	}
	return 0;
}

//返回对子个数，若没有返回0 
int duizi()
{
	int res=0;
	int size[14]={0};
	for(int i=0;i<13;i++){
		if(pai[i]%13==0&&pai[i]!=0) size[13]++;
		else size[pai[i]%13]++;
	} 
	
	for(int i=1;i<=13;i++) while(size[i]>=2){
		res++;size[i]-=2;
	}
	return res;
}

void fill1()
{
	//将剩下的插入所有空位 
	for(int i=0;i<3;i++)
	{
		if(up[i]==0)
		{
			for(int j=12;j>=0;j--)
			if(pai[j]!=0)
			{
				up[i]=pai[j];pai[j]=0;break;
			}
		}
	}
	
	for(int i=0;i<5;i++)
	{
		if(middle[i]==0)
		{
			for(int j=12;j>=0;j--)
			if(pai[j]!=0)
			{
				middle[i]=pai[j];pai[j]=0;break;
			}
		}
	}
	
	for(int i=0;i<5;i++)
	{
		if(bottom[i]==0)
		{
			for(int j=12;j>=0;j--)
			if(pai[j]!=0)
			{
				bottom[i]=pai[j];pai[j]=0;break;
			}
		}
	}
	
	
	
}


void fill2()
{
	int tmp,dz[2]; 
	
	
	
	
	if(duizi()>=1)
	{
		if(maxi==0&&maxj==7)
		{
			int ans=duizi();
			int all[5][2],num=0;
			for(int i=0;i<13;i++)
			{
				
				if(pai[i]==0) continue;
				
				for(int j=0;j<13;j++)
				{
					if(j==i||pai[j]==0) continue;
					if(pai[i]%13==pai[j]%13)
					{
						all[num][0]=pai[i];all[num][1]=pai[j];pai[i]=0;pai[j]=0;num++;
						break;
					}
				}
				
				if(num==5) break;
					
			}
			
			if(ans>=1)
			{
				bottom[0]=all[num-1][0];bottom[1]=all[num-1][1];num--;
			}
			
			if(ans>=2)
			{
				bottom[2]=all[num-1][0];bottom[3]=all[num-1][1];num--;
			}
			
			if(ans>=3)
			{
				middle[0]=all[num-1][0];middle[1]=all[num-1][1];num--;
			}
			
			if(ans>=4)
			{
				middle[2]=all[num-1][0];middle[3]=all[num-1][1];num--;
			}
			if(ans>=5)
			{
				up[0]=all[num-1][0];up[1]=all[num-1][1];num--;
			}
			
		//中下均是对子	
		//1个，放在下；2个，放在下；3个对子，上中下各一个，且从小到大；4个，上1个，中1个，下两个；5个，1,2,2； 
		}	
		else if(maxi!=0&&maxj==7)
		{
			//中是对子 
			//1，中；2,110；3,120；
			int ans=duizi(); 
			if(ans>=1)	
			{
				int sign=0;
				for(int i=0;i<13;i++)
				{
					
					if(pai[i]==0) continue;
					
					for(int j=0;j<13;j++)
					{
						if(j==i||pai[j]==0) continue;
						if(pai[i]%13==pai[j]%13)
						{
							dz[0]=pai[i];dz[1]=pai[j];pai[i]=0;pai[j]=0;
							sign=1;
							break;
						}
					}
					
					if(sign==1) break;
				}
				
				middle[0]=dz[0];middle[1]=dz[1];
			}
			
			if(ans>=2)
			{	
				int sign=0;
				for(int i=0;i<13;i++)
				{
					
					if(pai[i]==0) continue;
					
					for(int j=0;j<13;j++)
					{
						if(j==i||pai[j]==0) continue;
						if(pai[i]%13==pai[j]%13)
						{
							dz[0]=pai[i];dz[1]=pai[j];pai[i]=0;pai[j]=0;
							sign=1;
							break;
						}
					}
					
					if(sign==1) break;
				}
				
				middle[2]=dz[0];middle[3]=dz[1];
			}
			
			if(ans>=3)
			{
				int sign=0;
				for(int i=0;i<13;i++)
				{
					
					if(pai[i]==0) continue;
					
					for(int j=0;j<13;j++)
					{
						if(j==i||pai[j]==0) continue;
						if(pai[i]%13==pai[j]%13)
						{
							dz[0]=pai[i];dz[1]=pai[j];pai[i]=0;pai[j]=0;
							sign=1;
							break;
						}
					}
					
					if(sign==1) break;
				}
				
				up[0]=dz[0];up[1]=dz[1];
			}
			
			
			
		}
		else if(maxi!=0&&maxj!=7)
		{
			//上是1对子 
			int sign=0;
			for(int i=0;i<13;i++)
			{
				
				if(pai[i]==0) continue;
				
				for(int j=0;j<13;j++)
				{
					if(j==i||pai[j]==0) continue;
					if(pai[i]%13==pai[j]%13)
					{
						dz[0]=pai[i];dz[1]=pai[j];pai[i]=0;pai[j]=0;
						sign=1;
						break;
					}
				}
				
				if(sign==1) break;
			}
			
			up[0]=dz[0];up[1]=dz[1];
			
			
		}else
		{
		}
		


	}
	
	fill1();
}

void exchange()
{
	//判断bottom和middle是否倒水，调整牌序 
	if(maxi>maxj)
	{
		int tmpt;
		for(int i=0;i<5;i++)
		{
			tmpt=bottom[i];bottom[i]=middle[i];middle[i]=tmpt;
		 } 
	}
	else if(maxi==maxj)
	{
		//同种牌型大小	
	}else
	{
	}
}


int outter(int t)
{
	int signal=0;
		switch(t)
			{
				case 1:{
					if(ths()==1){
						tmpi=1;sum+=7;signal=1;
					}
					break;
				}
				
				case 2:{
					if(tz()==1){
						tmpi=2;sum+=6;signal=1;
					}
					break;
				}
				
				case 3:{
					if(hl()==1){
						tmpi=3;sum+=5;signal=1;
					}
					break;
				}
				
				case 4:{
					if(th()==1){
						tmpi=4;sum+=4;signal=1;
					}
					break;
				}
				
				case 5:{
					if(sz()==1){
						tmpi=5;sum+=3;signal=1;
					}
					break;
				}
			}
		return signal;
}


int inner(int t)
{
	switch(t)
			{
				case 1:{
					if(ths()==1){
						tmpj=1;sum+=7;return 1;
					}
					break;
				}
				
				case 2:{
					if(tz()==1){
						tmpj=2;sum+=6; return 1;
					}
					break;
				}
				
				case 3:{
					if(hl()==1){
						tmpj=3;sum+=5; return 1;
					}
					break;
				}
				
				case 4:{
					if(th()==1){
						
			//			cout<<endl<<"内循环找到同花！！！"<<endl; 
						tmpj=4;sum+=4; return 1;
					}
					break;
				}
				
				case 5:{
					if(sz()==1){
						tmpj=5;sum+=3; return 1;
					}
					break;
				}
				
				case 6:{
					if(st()==1){
						tmpj=6;sum+=2; return 1;
					}
					break;
				}
				
				case 7:{
					tmpj=7;sum+=duizi(); return 1;
					break;
				}
			}
			return 0;	
}



int main()
{
	int tmp,max=0;
	
	freopen("d:\\webgame\\game\\test.txt", "r", stdin);
	for(int i=0;i<13;i++) cin>>Pai[i];
	fclose(stdin);
	
	
	for(int i=0;i<12;i++)
	for(int j=0;j<12-i;j++)
	if(Pai[j]>Pai[j+1]){
		tmp=Pai[j];Pai[j]=Pai[j+1];Pai[j+1]=tmp;
	}
	
	int tt[13];
	for(int i=1;i<=5;i++)
	{
		for(int j=0;j<13;j++) pai[j]=Pai[j];//pai每次循环变一次，Pai始终不变。
		
		tmpi=0;tmpj=0;sum=0;
		
		
	//	cout<<endl<<"外循环第"<<i<<"次开始:"<<endl;
		int sign=outter(i);
	//	cout<<"外循坏第"<<i<<"次的返回值:"<<sign<<endl;
		
		if(i==5&&sign==0) sign=1;   //第一次优先查找到顺子牌，若没有直接进入第二次优先查找， 
		if(sign==0) continue;
		
		for(int l=0;l<13;l++) tt[l]=pai[l];
		int oldsum=sum;
		
		for(int j=1;j<=7;j++)
		{
			sum=oldsum;
			for(int l=0;l<13;l++) pai[l]=tt[l];
	//		cout<<endl<<"内循环"<<j<<"轮次"<<endl;
			
			
//			if(j==4) 
//			for(int q=0;q<13;q++) cout<<pai[q]<<" ";cout<<endl;
			
			if(inner(j)==1)
			{
				if(sum>max)
				{
					maxi=tmpi;maxj=tmpj;max=sum;
				}
				break;
			}
			
		}
		
	//	cout<<"maxi="<<maxi<<"  maxj="<<maxj<<" max="<<max<<endl;
	//	cout<<"循环结束"<<endl<<endl;
	}
//	cout<<"maxi="<<maxi<<"  maxj="<<maxj<<" max="<<max<<endl;
	
	
	for(int i=0;i<3;i++) up[i]=0;
	for(int i=0;i<5;i++) middle[i]=0;
	for(int i=0;i<5;i++) bottom[i]=0;
	
	for(int j=0;j<13;j++) pai[j]=Pai[j];
	key1=1;
	outter(maxi);
	key1=0;
	
//	for(int j=0;j<13;j++) cout<<pai[j]<<" ";cout<<endl;
	
	key2=1;
	inner(maxj);
//	for(int j=0;j<13;j++) cout<<pai[j]<<" ";cout<<endl;
	
	fill2();
	exchange();
		
//	cout<<"自动摆牌如下:"<<endl;
	
	freopen("d:\\webgame\\game\\test.txt", "w", stdout);
	for(int i=0;i<3;i++)
	cout<<up[i]<<" ";
//	cout<<endl;
	for(int i=0;i<5;i++)
	cout<<middle[i]<<" ";
//	cout<<endl;
	for(int i=0;i<5;i++)
	cout<<bottom[i]<<" ";

	fclose(stdout);
	return 0;
}

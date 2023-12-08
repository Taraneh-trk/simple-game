// author  =>   taraneh
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
const int weight  = 22;    
const int height  = 22;
const int size = weight * height;
int map[size]; 
const int tins = 20;
const int tsqr = 40;
int xsqr[tsqr],ysqr[tsqr];
int xins[tins],yins[tins];
int tm = 1;
int headx;  
int heady; 
int *direction = new int[2];
bool flagcheck = false;
int chchekback;

void checkback1()      
{
	if(map[headx + heady * weight] == -3 || map[headx + heady * weight] == -4 || map[headx + heady * weight] == -1)
	{
		flagcheck = true;
		if(map[headx + heady * weight] == -3){
			chchekback = -3; 
		}else if(map[headx + heady * weight] == -4){
			chchekback = -4; 
		}else if(map[headx + heady * weight] == -1){
			chchekback = -1; 
		}
	}else{
		flagcheck = false;
	}
}
void checkback2()  
{
	if(flagcheck)
	{
		if(chchekback == -3){ 
			map[headx + heady * weight] = -3;
		}else if(chchekback == -4){
			map[headx + heady * weight] = -4;
		}else if(chchekback == -1){ 
			map[headx + heady * weight] = -1;
		}
	}
}
void wallacdirection(int pos)         
{
	int *dir = new int[2];
	if(pos == 2){
		if(heady%2!=0){
			dir[0] = -1;
			dir[1] = 0;
		}else if(heady%2==0){
			dir[0] = 1;
			dir[1] = 0;
		}
	}else if(pos == 3){
		if(heady%2!=0){
			dir[0] = -1;
			dir[1] = 0;
		}else if(heady%2==0){
			dir[0] = 1;
			dir[1] = 0;
		}
	}else if(pos == 4){
		if(headx%2==0){
			dir[0] = 0;
			dir[1] = -1;
		}else if(headx%2!=0){
			dir[0] = 0;
			dir[1] = 1;
		}
	}else if(pos == 5){
		if(headx%2==0){
			dir[0] = 0;
			dir[1] = -1;
		}else if(headx%2!=0){
			dir[0] = 0;
			dir[1] = 1;
		}
	}
	direction = dir;
}
void wallacdirection2(int pos)
{
	int *dir = new int[2];
	if(direction[0] == -1 && direction[1] == 0){
		direction[0] = 1;
		direction[1] = 0;
	}else if(direction[0] == 1 && direction[1] == 0){
		direction[0] = -1;
		direction[1] = 0;
	}else if(direction[0] == 0 && direction[1] == 1){
		direction[0] = 0;
		direction[1] = -1;
	}else if(direction[0] == 0 && direction[1] == -1){
		direction[0] = 0;
		direction[1] = 1;
	}
	switch(pos)
	{
		case 2:
			if(direction[0] == -1 && direction[1] == 0){
				dir[0] = 0;
				dir[1] = 1;
			}else{
				dir[0] = -1;
				dir[1] = 0;
			}
			break;
		case 3:
			if(direction[0] == 1 && direction[1] == 0){
				dir[0] = 0;
				dir[1] = 1;
			}else{
				dir[0] = 1;
				dir[1] = 0;
			}
			break;
		case 4:
			if(direction[0] == -1 && direction[1] == 0){
				dir[0] = 0;
				dir[1] = -1;
			}else{
				dir[0] = -1;
				dir[1] = 0;
			}
			break;
		case 5:
			if(direction[0] == 1 && direction[1] == 0){
				dir[0] = 0;
				dir[1] = -1;
			}else{
				dir[0] = 1;
				dir[1] = 0;
			}
			break;
	}
	
	direction = dir;
}
void initialdirection()
{
	int *dir = new int[2];
	if(map[headx+(heady-1)*weight] != -1 && map[headx+(heady+1)*weight] != -1 && map[headx+1+heady*weight] != -1 && map[headx-1+heady*weight] != -1){
			int randnum;
    	    srand((unsigned)time(NULL));
    	    randnum = rand()%(2-1+1)+1;
			if(headx%2==0 && heady%2==0){
				if(randnum==1){
					dir[0] = 1;
					dir[1] = 0;
				}else if(randnum==2){
					dir[0] = 0;
					dir[1] = -1;
				}
			}else if(headx%2==0 && heady%2!=0){
				if(randnum==1){
					dir[0] = 1;
					dir[1] = 0;
				}else if(randnum==2){
					dir[0] = 0;
					dir[1] = 1;
				}
			}else if(headx%2!=0 && heady%2==0){
				if(randnum==1){
					dir[0] = -1;
					dir[1] = 0;
				}else if(randnum==2){
					dir[0] = 0;
					dir[1] = -1;
				}
			}else if(headx%2!=0 && heady%2!=0){
				if(randnum==1){
					dir[0] = -1;
					dir[1] = 0;
				}else if(randnum==2){
					dir[0] = 0;
					dir[1] = 1;
				}
			}
			direction = dir;
	}else{
		if(map[headx+(heady-1)*weight] == -1 && map[headx+1+heady*weight] == -1){
			wallacdirection2(2);
		}else if(map[headx+(heady-1)*weight] == -1 && map[headx-1+heady*weight] == -1){
			wallacdirection2(3);
		}else if(map[headx+(heady+1)*weight] == -1 && map[headx+1+heady*weight] == -1){
			wallacdirection2(4);
		}else if(map[headx+(heady+1)*weight] == -1 && map[headx-1+heady*weight] == -1){
			wallacdirection2(5);
		}else if(map[headx+(heady-1)*weight] == -1){
			wallacdirection(2);
		}else if(map[headx+(heady+1)*weight] == -1){
			wallacdirection(3);
		}else if(map[headx+1+heady*weight] == -1){
			wallacdirection(4);
		}else if(map[headx-1+heady*weight] == -1){
			wallacdirection(5);
		}
	}
}
void directionProducer()
{
	if(map[headx+(heady-1)*weight] == -1 && map[headx+1+heady*weight] == -1){
			wallacdirection2(2);
		}else if(map[headx+(heady-1)*weight] == -1 && map[headx-1+heady*weight] == -1){
			wallacdirection2(3);
		}else if(map[headx+(heady+1)*weight] == -1 && map[headx+1+heady*weight] == -1){
			wallacdirection2(4);
		}else if(map[headx+(heady+1)*weight] == -1 && map[headx-1+heady*weight] == -1){
			wallacdirection2(5);
		}else if(map[headx+(heady-1)*weight] == -1 && direction[0] == 0 && direction[1] == -1){
			wallacdirection(2);
		}else if(map[headx+(heady+1)*weight] == -1 && direction[0] == 0 && direction[1] == 1){
			wallacdirection(3);
		}else if(map[headx+1+heady*weight] == -1 && direction[0] == 1 && direction[1] == 0){
			wallacdirection(4);
		}else if(map[headx-1+heady*weight] == -1 && direction[0] == -1 && direction[1] == 0){
			wallacdirection(5);
		}
}
void direcmovewallac1(int hx,int hy)
{
	headx = hx;
	heady = hy;
	int *dir = new int[2];
	directionProducer();
	dir = direction;
	int dx = dir[0];
	int dy = dir[1];
	headx+=dir[0];
	heady+=dir[1];
	int x = headx;
	int y = heady;
	int xt = x;
	int yt = y;
	if(map[headx + heady * weight] == -3 || map[headx + heady * weight] == -4)
	{
		int randnum;
    	  srand((unsigned)time(NULL));
    	  randnum = rand()%(2-1+1)+1;
    	  if(randnum == 1)
    	  {
    	  	if(x%2==0 && dx!=0 && dy!=-1){//| p
    	  		y--;
			  	direction[0] = 0;
				direction[1] = -1;
			  }else if(x%2!=0 &&  dx!=0 && dy!=1){//| b
			  	y++;
			  	direction[0] = 0;
				direction[1] = 1;
			  }else if(y%2==0 &&  dx!=1 && dy!=0){// <-
			  	x++;
				direction[0] = 1;
				direction[1] = 0;
			  }else if(y%2!=0 && dx!=-1 && dy!=0){// ->
			  	x--;
			  	direction[0] = -1;
				direction[1] = 0;
			  }
		  }else{
		  	switch(dx)
			  {
			  	case 0:
			  		if(dy == 1){
			  			y++;
					  }else{
					  	y--;
					  }
			  		break;
			  	case 1:
			  		x++;
			  		break;
			  	case -1:
			  		x--;
			  		break;
			  }
		  }
		  if(map[x + y * weight] == -1){ 
				direcmovewallac1(xt,yt);
				return ;
		  }
	}
	
	headx = x;
	heady = y;
	checkback1();
	map[headx + heady * weight] = 1 +1;
	checkback2();
	
}
void move()             
{
	int dx = direction[0];
	int dy = direction[1];
    int x = headx + dx;
    int y = heady + dy;
    int xt = x;
	int yt = y;
    if (map[x + y * weight] == -3 || map[x + y * weight] == -4){
    	  int randnum;
    	  srand((unsigned)time(NULL));
    	  randnum = 1+rand()%(2);
    	  if(randnum == 1)
    	  {
    	  	if(x%2==0 && dx!=0 && dy!=-1){//| p
    	  		y--;
			  	direction[0] = 0;
				direction[1] = -1;
			  }else if(x%2!=0 &&  dx!=0 && dy!=1){//| b
			  	y++;
			  	direction[0] = 0;
				direction[1] = 1;
			  }else if(y%2==0 &&  dx!=1 && dy!=0){// <-
			  	x++;
				direction[0] = 1;
				direction[1] = 0;
			  }else if(y%2!=0 && dx!=-1 && dy!=0){// ->
			  	x--;
			  	direction[0] = -1;
				direction[1] = 0;
			  }
		  }else{
		  	switch(dx)
			  {
			  	case 0:
			  		if(dy == 1){
			  			y++;
					  }else{
					  	y--;
					  }
			  		break;
			  	case 1:
			  		x++;
			  		break;
			  	case -1:
			  		x--;
			  		break;
			  }
		  }
		  
    }
	
	if(map[x + y * weight] == -1){ 
		direcmovewallac1(xt,yt);
		return ;
	}
	
	// it use for cars do not eat each other when they are in the same location
	if(map[x + y * weight] > 0)
	{
		headx = x;
	    heady = y;
	    checkback1();
	    map[headx + heady * weight]+=1;
	    checkback2();
	    return ;
	}
	
    headx = x;
    heady = y;
    checkback1();
    map[headx + heady * weight] = 1 +1;
    checkback2();
}
void Generate(int *car1,int *direc1)
{
    srand((unsigned)time(NULL));
    int tcar = ::tm;
    int car[tcar][2];
	for(int i=0;i<tcar;i++)
		for(int j=0;j<2;j++)
			car[i][j]=*((car1+i*tcar)+j);
	int direc[tcar][2];
	for(int i=0;i<tcar;i++)
		for(int j=0;j<2;j++)
			direc[i][j]=*((direc1+i*tcar)+j);
	
    for(int i=0;i<tcar;i++)
    {
    	do{
    		headx = 2+rand()%(weight-2);
		    heady = 2+rand()%(height-2);
		}while(map[headx + heady * weight] != 0);
		map[headx + heady * weight] = 1;
	    initialdirection();
	    car[i][0] = headx;   //*((car+i)+0)
		car[i][1] = heady;  //*((car+i)+1)
		direc[i][0] = direction[0];  //*((direc+i)+0)
		direc[i][1] = direction[1]; //*((direc+i)+1)
	}
   	for(int i=0;i<tcar;i++)
		for(int j=0;j<2;j++)
			*((car1+i*tcar)+j) = car[i][j];
    for(int i=0;i<tcar;i++)
		for(int j=0;j<2;j++)
			*((direc1+i*tcar)+j) = direc[i][j];
    
	for(int i=0;i<tins;i++)
	{
		do{
			xins[i] = rand()%(weight-2)+1;
			yins[i] = rand()%(height-2)+1;
		}while(map[xins[i]+weight*yins[i]] != 0);
		map[xins[i]+weight*yins[i]] = -3;
	}
	
	for(int i=0;i<tsqr;i++)
	{
		do{
			xsqr[i] = rand()%(weight-2)+1;
			ysqr[i] = rand()%(height-2)+1;
		}while(map[xsqr[i]+weight*ysqr[i]] != 0);
		map[xsqr[i]+weight*ysqr[i]] = -4;
	}
}
char ChangeToChar(int m)
{
	// -1 => walls    1 => cars    -3 => intersection    -4 => square
	char ch;
	if(m == -4)
    	ch = '@';
    else if(m == -3)
    		ch = '#';
    	else if(m == -1)
    			ch = 'w';
    		else if(m == 0)
    			ch = ' ';
    			else if(m == 1)
    				ch = '*';
    				else if(m>0)
    					ch = '*';
    					
	return ch;
}
int main()
{
	cout<<"enter the number of car : ";
	cin>>::tm;
	int duration;
	cout<<"enter duration you want (second): ";
	cin>>duration;
	
	for(int i=0;i<size;i++)
		map[i] = 0;
	//left & right
	for(int x=0;x<weight;x++)
	{
		map[x] = -1;
		map[x + (height-1)*weight] = -1;
	}
	//top & bottom
	for(int y=0;y<height;y++)
	{
		map[0 + y*weight] = -1;
		map[(weight-1) + y*weight] = -1;
	}
	
	int car[::tm][::tm];
	int direc[::tm][::tm];
	Generate((int *)car,(int *)direc);
	int k=0;
	int tcar = ::tm;
	
	time_t now = time(0);    //second
	unsigned long long int nowt = now;
	while(now != nowt+duration)
	{	
		for(int i=0;i<tcar;i++)
		{
			headx = car[i][0];
			heady = car[i][1];
			direction[0] = direc[i][0];
			direction[1] = direc[i][1];
			if(k != 0)
				directionProducer();
			move();
			car[i][0] = headx;
			car[i][1] = heady;
			direc[i][0] = direction[0];
			direc[i][1] = direction[1];
		}
		k++;
		for(int i=0;i<size;i++)
        	if(map[i]>0) 
			{
				map[i]--;
			}
		
		system("cls");
		
		for(int x=0;x<weight;x++)
		{
			for(int y=0;y<height;y++)
				cout<<ChangeToChar(map[x+y*weight]);
			
			cout<<endl;
		}
		
		_sleep(500);
		now = time(0);
	}
	
	getch();
	return 0;
}

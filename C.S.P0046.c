#include<stdio.h>
#include<math.h>
#include<limits.h>
/*
 Purpose: Ham kiem tra gia tri nhap vao tu ban phim
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int inputCheck(int min,int max){
	// Bien min la gia tri nho nhat cho phep nhap vao, bien max la gia tri lon nhat cho phep nhap vao
	int check,n;
	// Bien check duoc gan voi lenh scanf de kiem tra cac ki tu nhap vao
	char ch;
	// Bien ch de kiem tra phim enter
	do{
		fflush(stdin);
		// xoa bo nho dem
		check = scanf("%d%c",&n,&ch);
		// bien check duoc gan cho scanf de kiem tra ki tu dc nhap vao la 1 so va 1 ki tu enter
		if( ch=='\n' && check == 2){
			// neu ch la phim enter va nguoi dung nhap vao 1 so va 1 ki tu thi se chay cau lenh trong if
			if(n >= min && n <= max ){
				// neu gia tri n nhap vao nam trong khoang min -> max thi break khoi vong lap
				break;
			}
			else printf("Out of range!\nPlease try again!\n");
			// Neu gia tri n nhap vao khong nam trong khoang min max thi yeu cau nguoi dung nhap lai
		}else printf("INVALID input! Please try again!\n");
		// Neu nguoi dung nhap qua 2 ki tu hoac nhap cac ki tu khac so dau tien thi se yeu cau nhap lai
	}while(1);
	// vong lap luon luon chay den khi break
	return n;
}
/*
 Purpose: Ham kiem tra so nguyen to
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int isPrime(int n){
	int i;
	// Bien i lam bien chay
	if(n<2) return 0;
	// neu n < 2 thi do khong phai la so nguyen to
	else 
		for(i=2;i<=sqrt(n);i++)
		//Neu n>=2 thi chay vong lap for cho n chia lan luot tu 2 den can bac 2 cua n
		if (n%i==0)
		// Neu n ma chia het cho 1 so bat ki nam giua khoang 2 den can bac 2 cua n thi so do k phai so nguyen to
			return 0;
	// Neu nhu khong chia het cho so nao trong khoang do thi n chinh la so nguyen to
	return 1;
}
/*
 Purpose: Ham in ra n so nguyen to dau tien
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void firstPrime(){
	int n,i=2;
	// Bien n de nhan gia tri tu ham input, bien i la cac so can check de in ra
	int dem = 0;
	// bien dem se dem cac so nguyen to
	printf("Please enter a number in range (1-50)\nNumber of primes:");
	n= inputCheck(0,50);
	// n se nhan gia tri tra ve tu ham inputCheck
	while(dem<n){
		// vong lap se chay den khi nao dem >= n
		if(isPrime(i) == 1){
			// Neu so i la so nguyen to thi so i se duoc in ra va bien dem se tang len 1 
			printf("%d ",i);
			dem++;
		}
		// tang dan i len de kiem tra 
		i++;
	}
}
/*
 Purpose: Ham kiem tra binh phuong
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int isPerfectSquare(int x){
	int s= sqrt(x);
	// Bien s duoc gan cho can bac 2 cua x nhung chi lay phan nguyen
	return (s*s==x);
	// Tra ve True or False neu x khong phai la so chinh phuong thi s*s<x cho gia tri False neu x la so chinh phuong tuc la 
	// s*s= x thi khi do se tra ve gia tri True
}
/*
 Purpose: Ham kiem tra so fibonacci
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
int isFibonacci(int n)
{	// Cong thuc de kiem tra so fibonacci do chinh la 1 hoac ca 2 phep kiem tra binh phuong o ben duoi cho gia tri True 
	// Neu khong co phep nao trong 2 phep duoi cho gia tri True(1) thi so do k phai la so fibonacci
     return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4); 
}
	// vd: 5*2*2 + 4 = 24 va 5*2*2 -4 =16 =4^2 -> 2 la so fibo 
	// vd: 6*2*2 + 4 =28 va 5*2*2 - 4 = 20 -> 6 khong phai la so fibo
/*
 Purpose: Ham kiem tra so fibonacci va in ra ket qua
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void fibonacciElement(){
	int n;
	// bien n nhan gia tri tu ham input
	printf("Number tested:");
	n = inputCheck(0,50);
	if(isFibonacci(n)==1) printf("It's a Fibonacci term");
	else printf("It's not a Fibonacci term");
}
/*
 Purpose: Ham tinh tong cac chu so tu 1 so duoc nhap vao
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void sumDigits(){
	int n;
	// Bien n de nhap gia tri nhap vao
	int sum = 0;
	// Bien sum de tinh tong
	printf("Enter an integer:");
	n = inputCheck(0,INT_MAX);
	while(n>0){
		// tinh tong bang cach chia lay du so n cho 10 roi cong vao sum roi lay n chia cho 10 den khi no nho hon 0 thi thoi
		sum = sum +(n%10);
		n = n/10;
	}
	printf("Sum of it's digits: %d",sum);
}
/*
 Purpose: Ham bieu thi cac lua chon cho nguoi dung va dan den cac ham thuc hien nhiem vu do
 Author: Vu Tien Khoi HE141137
 Date: 29/02/2020
*/
void display(){
	printf("1-The first primes\n");
	printf("2-Fibonacci element\n");
	printf("3-Sum of digits\n");
	printf("Choose an option:");
	int choice = inputCheck(1,3);
	switch(choice){
		case 1:
			firstPrime();
			break;
		case 2:
			fibonacciElement();
			break;
		case 3:
			sumDigits();
			break;
		default:
			break;
	}
}
/*
 Purpose: Ham check yes/no hoi nguoi dung muon tiep tuc hay thoat chuong trinh
 Author :Vu Tien Khoi HE141137
 Date   :29/2/2020
*/
int checkYN()
{
	int check;
	// bien check dung de kiem tra cac ki tu nhap vao
	char temp,enter;
	// bien temp la ki tu nhap vao, bien enter dung de kiem tra phim enter
	do{
		fflush(stdin);
		// xoa bo nho dem trong vong lap
		printf("\n---------------------------------------\nDo you want to continue or not(y/n):");
		check = scanf("%c%c",&temp,&enter);
		// gan check cho cau lenh nhap 1 ki tu va 1 phim enter
		if(check == 2 && enter == '\n'){
			// Neu nguoi dung chi nhap 1 ki tu va 1 phim enter thi se thuc hien cac cau lenh ben duoi
			if(temp == 'y' || temp == 'Y'){
				//Neu ki tu duoc nhap vao la y hoac Y thi se tra ve gia tri 1 phuc vu cho vong lap trong main
				return 1;
			}
			else if(temp == 'n' || temp == 'N'){
				// Neu ki tu la n hoac N thi se tra ve 0 phuc vu cho vong lap trong main
				return 0;
			}
			else{
				printf("Only input(y/n)!!!\n");
				// Neu ki tu nhap vao khong phai y hoac n thi yeu cau nhap lai
			}
		}
		else{
			printf("Only input(y/n)!!!\n");
			// Neu nguoi dung nhap qua 2 ki tu tinh ca phim enter thi se yeu cau nhap lai
		}
		
	}while(1);
	// Vong lap se luon luon chay den khi no return 1 hoac 0
}
int main(){
	do{
	display();
	}while(checkYN() == 1);
	// Vong lap se luon luon chay khi nguoi dung chon y hoac Y , dung lai khi nguoi dung chon n hoac N
}

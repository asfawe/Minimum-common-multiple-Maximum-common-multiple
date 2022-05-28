#include<stdio.h>

int min(int, int, int); // abc중 최소값 반환 
int gcd(int, int, int); //abc의 최대공약수 반환 
int lcm(int, int, int);

int main() 
{
	int a,b,c,g,l;
	printf("세정수 입력 : ");
	scanf("%d%d%d", &a, &b, &c);
	
	g = gcd(a,b,c);
	printf("최대공약수 : %d\n", g); 
	
	l = lcm(a,b,c);
	printf("최대공약수 : %d\n", l); 
	return 0;
}

int min(int a, int b, int c)
{
	int n;
	
	n = (a > b) ? b : a;
	n = (n > c) ? c : n;
	return n;
}

int mid(int a, int b, int c)
{
	int n;

	if (a > b) {
		if (b > c) {
			n = b;
		}
		else {
			if (a > c) {
				n = c;
			}
			else
				n = a;
		}
	}
	else {
		if (a > c) {
			n = a;
		}
		else {
			if (b > c) {
				n = c;
			}
			else {
				n = b;
			}
		}
	}
	
	
	
	
	return n;
}

int gcd(int a, int b, int c)
{
	int g=1, n, i=2;
	n = min(a,b,c);
	
	while(i <= n){
		if(a % i == 0 && b % i == 0 && c % i == 0){
			g *= i;
			a /= i; b /= i; c /= i;
			n = min(a,b,c);
			continue;
		}
		i++;
	}
	
	
	
	return g;
}

int lcm(int a, int b, int c)
{
	int L, n, i;
	
	n = mid(a,b,c);
	L = gcd(a,b,c); // 최대공약수 
	
	a /= L;  b /= L;  c /= L;
	
	i=2;
	while(i <= n){
		
		if(a % i == 0 && b % i == 0){
			L *= i;
			a /= i; b /= i;
			n = mid(a,b,c);
			continue;
		}
		else if(a % i == 0 && c % i == 0){
			L *= i;
			a /= i; c /= i;
			n = mid(a,b,c);
			continue;
		}
		
		else if(a % i == 0 && c % i == 0){
			L *= i;
			a /= i; c /= i;
			n = mid(a,b,c);
			continue;
		}
		i++;
	}
	return L * a * b *c;
}

// System Libraries
#include <stdio.h>

// Symbolic Constants
#define X(p) (p>0)?'T':'F'
#define COND(x) i=x;i>=0;--i
#define COND2 i=2;i>0;--i

// Function Prototypes
void title(char *str);

// Execution begins here
int main() {
	int p,q,r,t=1,c=0,i;

	title("Author: Jiwon Yoo\n");
	title("  Commutative Laws: p&&q=q&&p		p||q==q||p\n");
	printf("%3c%3c%6s%6s%6s%6s\n",'p','q',"p&&q","q&&p","p||q","q||p");
	for(COND(3)) {
		p=i&10; q=i&1; printf("%3c%3c%5c%5c%6c%6c\n",X(p),X(q),X(p&&q),X(q&&p),X(p||q),X(q||p));
	}

	title("  Associative Laws: (p&&q)&&r=p&&(q&&r)   (p||q)||r=p||(q||r)\n");
	printf("%3c%3c%3c%6s%6s%6s%6s%12s%12s%12s%12s\n",
			'p','q','r',"p&&q","q&&p","p||q","q||r","(p&&q)&&r)","p&&(q&&r)","(p||q)||r","p||(q||r)");
	for(COND(7)) {
		p=i&100; q=i&10; r=i&1;
		printf("%3c%3c%3c%5c%5c%6c%6c%10c%12c%12c%11c\n",
			X(p),X(q),X(r),X(p&&q),X(q&&r),X(p||q),X(q||r),X((p&&q)&&r),X(p&&(q&&r)),
			X((p||q)||r),X(p||(q||r)));
	}

	title("  Distributive Laws: p&&(q||r)=(p&&q)||(p&&r)     p||(q&&r)=(p||q)&&(p||r)   \n");
	printf("%3c%3c%3c%6s%6s%6s%6s%6s%6s%12s%16s%12s%16s\n",
			'p','q','r',"q||r","p&&q","p&&r","q&&r","p||q","p||r",
			"p&&(q||r)","(p&&q)||(p&&r)","p||(q&&r)","(p||q)&&(p||r)");
	for(COND(7)) {
		p=i&100; q=i&10; r=i&1;
		printf("%3c%3c%3c%4c%6c%6c%6c%6c%6c%9c%14c%15c%14c\n",
				X(p),X(q),X(r),X(q||r),X(p&&q),X(p&&r),X(q&&r),X(p||q),X(p||r),X(p&&(q||r)),
				X((p&&q)||(p&&r)),X(p||(q&&r)),X((p||q)&&(p||r)));
	}

	title("  Icentity Laws: p&&t=p       p||c=p\n");
	printf("%3c%3c%3c%7s%7s\n",'p','t','c',"p&&t","p||c");
	for(COND2) {
		p=i&10; printf("%3c%3c%3c%5c%7c\n",X(p),X(t),X(c),X(p&&t),X(p||c));
	}

	title("  Negation Laws: p||~p=t       p&&~p=c\n");
	printf("%3c%3c%3c%7s%7s\n",'p','t','c',"p||~p","p&&~p");
	for(COND2) {
		p=i&10;	printf("%3c%3c%3c%5c%7c\n",X(p),X(t),X(c),X(p||!p),X(p&&!p));
	}

	title("  Double Negative Laws: ~(~p)=p\n");
	printf("%3c%5s%7s\n",'p',"~p","~(~p)");
	for(COND2) {
		p=i&10; printf("%3c%5c%6c\n",X(p),X(!p),X(!(!p)));
	}

	title("  Icempotent Laws: p&&p=p       p||p=p\n");
	printf("%3c%7s%7s\n",'p',"p&&p","p||p");
	for(COND2) {
		p=i&10;	printf("%3c%5c%7c\n",X(p),X(p&&p),X(p||p));
	}

	title("  Universal Bounc Laws: p||t=t       p&&c=c\n");
	printf("%3c%3c%3c%7s%7s\n",'p','t','c',"p||t","p&&c");
	for(COND2) {
		p=i&10;	printf("%3c%3c%3c%5c%7c\n",X(p),X(t),X(c),X(p||t),X(p&&c));
	}

	title("  De Morgan's Laws: !(p&&q)=!p||!q		!(p||q)=!p&&!q\n");
	printf("%3c%3c%4s%4s%6s%10s%10s%10s%8s\n",
			'p','q',"!p","!q","p&&q","!(p&&q)","!p||!q", "!(p||q)", "!p&&!q");
	for(COND(3)) {
		p=i&10; q=i&1;
		printf("%3c%3c%4c%4c%4c%9c%11c%9c%9c\n",
			X(p),X(q),X(!p),X(!q),X(p&&q),X(!(p&&q)),X(!p||!q),X(!(p||q)),X(!p&&!q));
	}

	title("  Absorption Laws: p||(p&&q)=p		p&&(p||q)=p\n");
	printf("%3c%3c%6s%6s%12s%12s\n",'p','q',"p&&q","p||q", "p||(p&&q)", "p&&(p||q)");
	for(COND(3)) {
		p=i&10; q=i&1;
		printf("%3c%3c%4c%6c%10c%11c\n",X(p),X(q),X(p&&q),X(p||q),X(p||(p&&q)), X(p&&(p||q)));
	}

	title("  Negations of t and c: ~t=c       ~c=t\n");
	printf("%3c%3c%5s%5s\n",'t','c',"~t","~c");
	for(COND2) {
		t=i&10; c=i&1; printf("%3c%3c%5c%5c\n",X(t),X(c),X(!t),X(!c));
	}

	return 0;
}

void title(char *str) {
	printf("===================================================================================\n");
	printf("%s",str);
	printf("-----------------------------------------------------------------------------------\n");
}

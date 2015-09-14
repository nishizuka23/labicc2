void vai_estourar(){
	int a;
	printf("%p\n", &a);
	static int num = 1;
	num++;
	//printf("%d\n", num);
	vai_estourar();

}


int main(){
	vai_estourar();
}


/*
	Recursiva simples: 523833  11.568s
	Com 2 long double: 174487  3.575s
	Com 1 long double: 261781  5.519s
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;
	char n[11];
	int hantei(char []);

	printf("input natural number\n");
	scanf("%s", &n);

	i = hantei(n);

	if(i == 1){
		printf("YES: This is multiple of 3 or has '3' in digits\n");
	}else if(i == 0){
		printf("NO: This is not multiple of 3 and has no '3'\n");
	}else{
		printf("input error\n");
	}
}

int hantei(char n[])
// nが整数でない: return -1.
// nが3の倍数またはnに3が付く: return 1.
// どちらでもない: return 0.
{
	int i, num;
	int has_3 = 0;

	// nの各桁が数字以外を含んでいないかチェック
	for(i = 0; n[i] != '\0'; i++){
		// 数字以外の場合は、先頭かそれ以外かで分岐
		if(!isdigit(n[i])){
			// 先頭ならば、それが符号であるかチェック。符号ならばループに戻る。
			// 符号以外なら入力エラーの-1を返して呼び出し元に戻る。
			if(i == 0){
				if(n[0] != '+' && n[0] != '-'){
					return -1;
				}
			// 先頭以外に数字以外がが入っているならば入力エラー。
			}else{
				return -1;
			}
		}

		// 各桁が数字ならば、3かどうかチェック。3ならばhas_3の値を1に変更。
		// 1度でも3を含んでいる桁を発見したら、それ以降は検討しない。
		if(has_3 != 1 && n[i] == '3'){
			has_3 = 1;
		}
	}

	num = atoi(n);

	// 3を含んでいるかは検討済みなので、含んでいれば1を返す
	if(has_3 == 1){
		return 1;
	// nが3の倍数か検討
	}else if(num % 3 == 0){
		return 1;
	// 整数でありながら3を各桁に含まず、3の倍数でもない
	}else{
		return 0;
	}
}
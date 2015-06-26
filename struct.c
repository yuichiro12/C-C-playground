#include <stdio.h>

#define MOJI_MAX	30
#define SEITOSU_MAX	50

struct kojin_data{
	int id;
	char myoji[MOJI_MAX];
	char namae[MOJI_MAX];
	int age;
	float shincho;
	float taiju;
};

int main()
{
	int i, seitosu;
	struct kojin_data data[SEITOSU_MAX];

	scanf("%d", &seitosu);

	for(i = 0; i < seitosu; i++){
		scanf("%d", &data[i].id);
		scanf("%s", &data[i].myoji);
		scanf("%s", &data[i].namae);
		scanf("%d", &data[i].age);
		scanf("%f", &data[i].shincho);
		scanf("%f", &data[i].taiju);

		printf("出席番号%dの人の名前は%s %sです。\n", data[i].id, data[i].myoji, data[i].namae);
		printf("その人の年齢は%dで、身長、体重は%.1fcm、%.1fkgです。\n", data[i].age, data[i].shincho, data[i].taiju);
	}
}
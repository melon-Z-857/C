#include"Seqlist.h"
#include"Contact.h"

int FindByName(contact* con, char name[]) {
	for (int i = 0; i < con->size; i++) {
		if ((strcmp(name, con->arr[i].name)) == 0) {
			return i;
		}
	}
	return -1;
}

void InitContact(contact* con) {
	SLInit(con);
}

void DestroyContact(contact* con) {
	assert(con->arr != NULL);
	free(con->arr);
	con->arr = NULL;
	con->size = 0;
	con->capacity = 0;
}

void AddContact(contact* con) {
	SLCheckCapacity(con);
	printf("��������ϵ������ �Ա� ���� �绰 סַ(ÿ������һ��س�ȷ��):\n");
	PeoInfo tmp = { 0 };
	scanf("%s", tmp.name);
	scanf("%s", tmp.gender);
	scanf("%d", &tmp.age);
	scanf("%s", tmp.tel);
	scanf("%s", tmp.addr);
	con->arr[con->size] = tmp;
	con->size++;
}

void FindContact(contact* con) {
	printf("��������Ҫ���ҵ���ϵ������\n");
	char name[NAME_MAX];
	scanf("%s", name);
	if (FindByName(con, name) < 0) {
		printf("���ҵ���ϵ�˲�����\n");
	}
	else {
		printf("������%s �Ա�%s ���䣺%d �绰��%s סַ��%s\n",
			con->arr[FindByName(con, name)].name,
			con->arr[FindByName(con, name)].gender,
			con->arr[FindByName(con, name)].age,
			con->arr[FindByName(con, name)].tel,
			con->arr[FindByName(con, name)].addr);
	}
}

void DelContact(contact* con) {
	printf("��������Ҫɾ������ϵ������\n");
	char name[NAME_MAX];
	scanf("%s", name);
	if (FindByName(con, name) < 0) {
		printf("Ҫɾ������ϵ�˲�����\n");
	}
	else {
		SLErase(con, FindByName(con, name));
		printf("�ѳɹ�ɾ����ϵ��\n");
	}
}

void ModifyContact(contact* con) {
	printf("��������Ҫ�޸ĵ���ϵ������\n");
	char name[NAME_MAX];
	scanf("%s", name);
	if (FindByName(con, name) < 0) {
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
	}
	else {
		printf("�������޸ĺ���ϵ������ �Ա� ���� �绰 סַ(ÿ������һ��س�ȷ��):\n");
		PeoInfo tmp;
		scanf("%s", tmp.name);
		scanf("%s", tmp.gender);
		scanf("%d", &tmp.age);
		scanf("%s", tmp.tel);
		scanf("%s", tmp.addr);
		con->arr[FindByName(con, name)] = tmp;
		printf("�޸ĳɹ�\n");
	}
}

void ShowContact(contact* con) {
	printf("------------ͨѶ¼------------\n");
	for (int i = 0; i < con->size; i++) {
		printf("������%s �Ա�%s ���䣺%d �绰��%s סַ��%s\n",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr);
	}
	printf("------------------------------\n");
}
using namespace std;

/*=================================
		����� ���� ��� ���� ���
=================================*/
#include "cha1.h"
#include "po2.h"
#include "Moving.h"

//�÷��̾�
#define PLAYER cha1::getInstance()->Player
#define PLAYER2 cha1::getInstance()->Unit
//�÷��̾� ���̾�
#define playerlayer cha1::getInstance()->pl

//���巹�̾�
#define layer1 cha1::getInstance()->worldlayer

//��ӿ�
#define PO2 cha1::getInstance()->po2_start
#define Move cha1::getInstance()->mov

//����Ű �Է¿� �÷��׵�
#define flag_left cha1::getInstance()->flag_l
#define flag_right cha1::getInstance()->flag_r
#define left_stay cha1::getInstance()->left
#define flag_jump cha1::getInstance()->flag_j
#define jump_stay cha1::getInstance()->jmp_stay
#define flag_eat cha1::getInstance()->flag_e
#define GRA cha1::getInstance()->gravity

//���ſ� �ѹ� ���庯��
#define Trans cha1::getInstance()->trans_num
//��� üũ��
#define NUM cha1::getInstance()->_num

//����Ʈ
#define effect1 cha1::getInstance()->ef1
#define effect2 cha1::getInstance()->ef2
#define b_num cha1::getInstance()->bullet_num

//hp
#define HP cha1::getInstance()->hp
#define hp_layer cha1::getInstance()->hp_bar
using namespace std;

/*=================================
		사용자 정의 헤더 파일 목록
=================================*/
#include "cha1.h"
#include "po2.h"
#include "Moving.h"

//플레이어
#define PLAYER cha1::getInstance()->Player
#define PLAYER2 cha1::getInstance()->Unit
//플레이어 레이어
#define playerlayer cha1::getInstance()->pl

//월드레이어
#define layer1 cha1::getInstance()->worldlayer

//상속용
#define PO2 cha1::getInstance()->po2_start
#define Move cha1::getInstance()->mov

//방향키 입력용 플래그들
#define flag_left cha1::getInstance()->flag_l
#define flag_right cha1::getInstance()->flag_r
#define left_stay cha1::getInstance()->left
#define flag_jump cha1::getInstance()->flag_j
#define jump_stay cha1::getInstance()->jmp_stay
#define flag_eat cha1::getInstance()->flag_e
#define GRA cha1::getInstance()->gravity

//변신용 넘버 저장변수
#define Trans cha1::getInstance()->trans_num
//대시 체크용
#define NUM cha1::getInstance()->_num

//이펙트
#define effect1 cha1::getInstance()->ef1
#define effect2 cha1::getInstance()->ef2
#define b_num cha1::getInstance()->bullet_num

//hp
#define HP cha1::getInstance()->hp
#define hp_layer cha1::getInstance()->hp_bar
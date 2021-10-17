#pragma once
#include "Headers.h"

class Bitmap;
class Object
{
protected:
	// ** ������Ʈ�� �⺻ Transform
	Transform TransInfo;

	// ** �浹ü��  �⺻ Transform
	Transform Collider;
	Vector3 Offset;

	int HP;
	string strKey;
	bool Active;
	float Speed;
	int Power;
	// ** ��� �̹��� ����
	static map<string, Bitmap*> ImageList;
	static int MobNum;
	int Phase;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	// ** map���� ������ Image ���� �����̳ʺz Setting
	static void SetImageList(const map<string, Bitmap*>& _ImageList) { ImageList = _ImageList; }

	// ** map���� ������ Image ���� �����̳ʺz out
	static map<string, Bitmap*> GetImageList() { return ImageList; }

	// ** �̹����� ����ϴµ� ����ϴ� Key ���� out
	string GetKey() const { return strKey; }

	void SetHp(int& _hp) { HP = _hp; }
	int GetHp() { return HP; }

	void SetPower(int& _power) { Power = _power; }
	int GetPower() { return Power; }

	void SetPhase(int& _phase) { Phase = _phase; }
	int GetPhase() { return Phase; }
	static void SetMobNum(int& _mobnum) { MobNum = _mobnum; }
	static int GetMobNum() { return MobNum; }
	// ** ��ǥ�� Setting (Vector3)
	void SetPosition(Vector3 _position) { TransInfo.Position = _position; }

	// ** ��ǥ�� Setting (_x, _y)
	void SetPosition(float _x, float _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }

	// ** ��ǥ�� Vector3�� out
	Vector3 GetPosition() { return TransInfo.Position; }

	void SetScale(Vector3 _scale) { TransInfo.Scale = _scale; }

	// ** ũ�⸦ Vector3�� out
	Vector3 GetScale() { return TransInfo.Scale; }

	// ** �浹ü�� out.
	RECT GetCollider();
	
	Vector3 GetColliderPosition() { return Collider.Position; }
	Transform GetColliderTransform() { return Collider; }

	// ** �浹ü�� Setting
	void SetColliderPosition(Vector3 _position) { Collider.Position = _position; }
	void SetColliderPosition(float _x, float _y) { Collider.Position.x = _x; Collider.Position.y = _y; }
	
	// ** �浹ü�� Top ��ǥ�� ��ȯ.
	// ** ������Ʈ�� ����� ��� �̺�Ʈ �߻��� ��밡��.
	float GetRectTop() { return TransInfo.Position.y - (TransInfo.Scale.y / 2); }

	// ** ������ �������� �ִ°�� �Ʒ��� ���鿡�� ������ �Ǵٸ� �������� �����̵� Ȥ��
	// ** �Ϲ� �̵��ÿ� ������ �ϴܺκа� �浹�� ������ �� ����.
	float GetRectBottom() { return TransInfo.Position.y + (TransInfo.Scale.y / 2); }

	// ** ������Ʈ�� Ȱ��/��Ȱ�� �� [Ȯ��] �ϱ� ���� ��������� ���� ������� �ʰ�����. 
	bool GetActive() const { return Active; }

	// ** ������Ʈ�� Ȱ��/��Ȱ�� �� [Setting] �ϱ� ���� ��������� ���� ������� �ʰ�����. 
	void SetActive(const bool& _Active) { Active = _Active; }

public:
	Object();
	Object(const Transform& _rTransInfo) : TransInfo(_rTransInfo) { }
	virtual ~Object();
};


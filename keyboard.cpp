//�L�[�{�[�h�̃\�[�X�t�@�C��

//�w�b�_�t�@�C���ǂݍ���
#include "keyboard.h"

//�O���[�o���ϐ�
KEYBOARD keyboard;

//�֐�

/// <summary>
/// �L�[�̓��͏�Ԃ��X�V����
/// </summary>
VOID AllKeyUpdate(VOID)
{
	//���O�̃L�[���͂�����Ă���
	for (int i = 0; i < KEY_KIND_MAX; i++)
	{
		keyboard.oldAllKeyState[i] = keyboard.AllKeyState[i];
	}

	//���ׂẴL�[���͏�Ԃ𓾂�
	GetHitKeyStateAll(keyboard.TempKeyState);

	//������Ă���L�[�̎��Ԃ��X�V����
	for (int i = 0; i < KEY_KIND_MAX; i++)
	{
		//�L�[�{�[�h�������Ă���Ƃ�
		if (keyboard.TempKeyState[i] != 0)
		{
			keyboard.AllKeyState[i]++;			//�����Ă鎞�Ԃ����Z
		}
		else
		{
			keyboard.AllKeyState[i] = 0;		//�����Ă鎞�Ԃ�0�ɂ��ǂ�
		}
	}
	return;
}

/// <summary>
///  �L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
/// </summary>
/// <param name="KEY_INPUT_">//�L�[�R�[�h</param>
/// <returns>//�����Ă�����TRUE</returns>
BOOL KeyDown(int KEY_INPUT_)
{
	if (keyboard.AllKeyState[KEY_INPUT_] != 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/// <summary>
///  �L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
/// </summary>
/// <param name="KEY_INPUT_">//�L�[�R�[�h</param>
/// <returns>//�����Ă���TRUE</returns>
BOOL KeyUp(int KEY_INPUT_)
{
	if (
		keyboard.oldAllKeyState[KEY_INPUT_] != 0		//�ȑO�͉����Ă���
		&&keyboard.AllKeyState[KEY_INPUT_] == 0		//���݉����Ă��Ȃ�
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/// <summary>
///  �L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
/// </summary>
/// <param name="KEY_INPUT_">//�L�[�R�[�h</param>
/// <returns>//�����Ă���TRUE</returns>
BOOL KeyClick(int KEY_INPUT_)
{
	if (
		keyboard.oldAllKeyState[KEY_INPUT_] != 0		//�ȑO�͉����Ă���
		&& keyboard.AllKeyState[KEY_INPUT_] == 0		//���݉����Ă��Ȃ�
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/// <summary>
/// �L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����
/// </summary>
/// <param name="KEY_INPUT__"></param>�L�[�R�[�h
/// <param name="MilliTime">�L�[�����������Ă���~���b</param>
/// <returns></returns>
BOOL KeyDownKeep(int KEY_INPUT_, int MilliTime)
{
	//1�b��1000�~���b
	float MilliSec = 1000.0f;

	//���������Ă��鎞�Ԃ́A�~���b���~FPS�l
	//��)�@1500�~���b����/1000�~���E���E1,5�b�~60FPS�E=�E90
	int UpdateTime = (MilliTime / MilliSec) * 60;

	if (keyboard.AllKeyState[KEY_INPUT_] > UpdateTime)
	{
		return TRUE;		//���������Ă���
	}
	else
	{
		return FALSE;		//���������Ă��Ȃ�
	}
}
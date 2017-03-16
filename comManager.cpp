#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_COM_ID (19)
#define MAX_COM_NUM (MAX_COM_ID + 1)
#define MIN_COM_ID (0)

enum
{
	COM_NOT_INSTALLED,
	COM_INSTALLED
};

typedef struct tagCOMPONENT_S COMPONENT_S; 

struct tagCOMPONENT_S
{
	int com_id;
	int state;
	//本组件依赖的组件列表
	list<COMPONENT_S> depend_com_list;
};

vector<COMPONENT_S> g_component_info (MAX_COM_NUM);

/*内部函数*/
bool isOutOfRange(int com_id)
{
	if (MAX_COM_ID < com_id || MIN_COM_ID > com_id)
	{
		return true;
	}
	
	return false;
}

bool isCircleRelate(int iDenpendantComId, int iAppendantComId)
{
	list<COMPONENT_S>::iterator l_iter;
	COMPONENT_S tmp_com = g_component_info[iDenpendantComId];

	if (iDenpendantComId == iAppendantComId)
	{
		return true;
	}

	l_iter = tmp_com.depend_com_list.begin();
	while (l_iter != tmp_com.depend_com_list.end())
	{
		if (l_iter->com_id == iAppendantComId)
		{
			return true;
		}

		if (true == isCircleRelate(l_iter->com_id, iAppendantComId))
		{
			return true;
		}
		else
		{
			l_iter++;
		}
	}

	return false;
}

bool isComInstalled(int com_id)
{
	return g_component_info[com_id].state == COM_INSTALLED ? true : false;
}

bool isComDependentByOther(int com_id)
{
	vector<COMPONENT_S>::iterator v_ter;
	list<COMPONENT_S>::iterator l_iter;

	for (v_ter == g_component_info.begin(); v_ter != g_component_info.end(); ++v_ter)
	{
		for (l_iter == v_ter->depend_com_list.begin(); l_iter != v_ter->depend_com_list.end(); ++l_iter)
		{
			if (l_iter->com_id == com_id)
			{
				return true;
			}
		}
	}

	return false;
}


/*需要实现的对外接口*/

void SysInitComponent()
{
	int index = 0;
	COMPONENT_S tmp_com;

	g_component_info.clear();
	for (index = 0; index < MAX_COM_NUM; index++)
	{
		tmp_com.com_id = index;
		tmp_com.state = COM_NOT_INSTALLED;
		g_component_info.push_back(tmp_com);
	}

	return;
}

int SetRelationshipOfComponents(int iDenpendantComId, int iAppendantComId)
{
	COMPONENT_S tmp_com;
	
	if (isOutOfRange(iDenpendantComId) || isOutOfRange(iAppendantComId))
	{
		return -1;
	}
	
	tmp_com = g_component_info[iDenpendantComId];

	if (isCircleRelate(iDenpendantComId, iAppendantComId))
	{
		return -1;
	}

	g_component_info[iAppendantComId].depend_com_list.push_back(tmp_com);

	return 0;
}

int AddComponent(int iComId)
{
	list<COMPONENT_S>::iterator l_iter;
	
	if (isOutOfRange(iComId))
	{
		return -1;
	}
	
	l_iter = g_component_info[iComId].depend_com_list.begin();

	if (isComInstalled(iComId))
	{
		return 0;
	}

	while (l_iter != g_component_info[iComId].depend_com_list.end())
	{
		if (isComInstalled(l_iter->com_id)) 
		{
			l_iter++;
			continue;
		}
		
		//g_component_info[l_iter->com_id].state = COM_INSTALLED;
		if (0 == AddComponent(l_iter->com_id))
		{
			l_iter++;
		}
		else
		{
			return -1;
		}
		
	}

	g_component_info[iComId].state = COM_INSTALLED;
	return 0;
}

int DeleteComponent(int iComId)
{
	list<COMPONENT_S>::iterator l_iter;
	
	if (isOutOfRange(iComId))
	{
		return -1;
	}

	if (!isComInstalled(iComId))
	{
		return 0;
	}

	if (isComDependentByOther(iComId))
	{
		return -1;
	}

	l_iter = g_component_info[iComId].depend_com_list.begin();
	while (l_iter != g_component_info[iComId].depend_com_list.end())
	{
		if (isComDependentByOther(l_iter->com_id))
		{
			break;
		}

		g_component_info[l_iter->com_id].state = COM_NOT_INSTALLED;
		l_iter++;
	}
	
	g_component_info[iComId].state = COM_NOT_INSTALLED;
	return 0;
}

void QueryComponents (char *pCompStatusArray)
{
	vector<COMPONENT_S>::iterator v_iter;
	int index = 0;

	for (v_iter = g_component_info.begin(); v_iter != g_component_info.end(); ++v_iter)
	{
		if (isComInstalled(v_iter->com_id))
		{
			pCompStatusArray[index] = '1';
		}
		else
		{
			pCompStatusArray[index] = '0';
		}

		index++;
	}
}

void DestroyComponents(void)
{
	g_component_info.clear();
	return;
}

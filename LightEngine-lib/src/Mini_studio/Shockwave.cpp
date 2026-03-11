#include "Shockwave.h"


//if (/*button de competences is pressed*/)
//{
//	Shockw
//}

void Shockwave::Attack()
{
	Scene* scene = dynamic_cast<Scene*>(GetScene());
	for(int i = 0;i < scene.GetEntityList.size();i++)
	{
		enemies* e = scene.GetEntityList[i];
		if (e->GetPosition())
		{

		}
	}
}

void Shockwave::TakeDamage()
{
	
}

void Shockwave::OnUpdate()
{

}

void Shockwave::OnDestroy()
{

}

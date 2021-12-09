#include "samochod.h"

Samochod::Samochod(list <Droga*> lD, int por_x, int por_y, string rO)
	:ObiektRuchomy::ObiektRuchomy(rO)
{
	srand(time(NULL));
	for (list<Droga*>::iterator it = lD.begin(); it != lD.end(); ++it)
	{
		gdzieMoznaPoruszyc.push_back((*it));
	}
	int rozmiarListy = lD.size();
	if (rozmiarListy > 0)
	{
		int los = (rand() % rozmiarListy);
		for (list<Droga*>::iterator it = lD.begin(); it != lD.end(); ++it)
		{
			if (los == 0)
			{
				polozenie_x = (*it)->polozenie_x+40;
				polozenie_y = (*it)->polozenie_y+40;
			}
			else
			{
				los--;
			}
		}
	}
}

void Samochod::updateDrog(list <Droga*> lD)
{
	gdzieMoznaPoruszyc.clear();
	for (list<Droga*>::iterator it = lD.begin(); it != lD.end(); ++it)
	{
		gdzieMoznaPoruszyc.push_back((*it));
	}
}

void Samochod::porusz()
{
	for (list<Droga*>::iterator it = gdzieMoznaPoruszyc.begin(); it != gdzieMoznaPoruszyc.end(); ++it)
	{
		if (polozenie_x == (*it)->polozenie_x - 60 && polozenie_y == (*it)->polozenie_y + 40)
		{
			gdzieMoznaPoruszyc.remove(*it);
			gdzieMoznaPoruszyc.push_back(*it);
			porusz_x = 1;
			porusz_y = 0;
			polozenie_x += porusz_x;
			polozenie_y += porusz_y;
			break;
		}
		else if (polozenie_y == (*it)->polozenie_y - 60 && polozenie_x == (*it)->polozenie_x + 40)
		{
			gdzieMoznaPoruszyc.remove(*it);
			gdzieMoznaPoruszyc.push_back(*it);
			porusz_x = 0;
			porusz_y = 1;
			polozenie_x += porusz_x;
			polozenie_y += porusz_y;
			break;
		}
		else if (polozenie_y == (*it)->polozenie_y + 140 && polozenie_x == (*it)->polozenie_x + 40)
		{
			gdzieMoznaPoruszyc.remove(*it);
			gdzieMoznaPoruszyc.push_back(*it);
			porusz_x = 0;
			porusz_y = -1;
			polozenie_x += porusz_x;
			polozenie_y += porusz_y;
			break;
		}
		else if (polozenie_x == (*it)->polozenie_x + 140 && polozenie_y == (*it)->polozenie_y + 40)
		{
			gdzieMoznaPoruszyc.remove(*it);
			gdzieMoznaPoruszyc.push_back(*it);
			porusz_x = -1;
			porusz_y = 0;
			polozenie_x += porusz_x;
			polozenie_y += porusz_y;
			break;
		}
	}
	polozenie_x += porusz_x;
	polozenie_y += porusz_y;
}
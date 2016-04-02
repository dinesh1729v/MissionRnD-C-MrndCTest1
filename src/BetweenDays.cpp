/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int isValid(int d,int m,int y)
{
	int  i, month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, leap = 0;
	if (y == 0)return 0;
	if (y % 4 == 0)leap = 1;
	if ((y % 100 == 0) && (y % 400 != 0))leap = 0;
	if (d <= 0 || d>31)return 0;
	if (m <= 0 || m>12)return 0;
	if (m == 2 && d > 29)return 0;
	if (m == 2 && leap == 1 && d <= 29)return 1;
	if (month[m - 1] < d)return 0;
	return 1;
}
int getDays(int d, int m, int y)
{
	int month[] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, leap = 0,days,i;
	if (y % 4 == 0)
	{
		days = 366;
		month[1] = 29;
	}
	if (y % 100 == 0 && y % 400 != 0)
	{
		days = 365;
		month[1] = 28;
	}
	for (i = 0; i < m - 1; i++)
		days -= month[i];
	days -= (d - 1);
	return days;

}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)return -1;
	int d1=0, d2=0, m1=0, m2=0, y1=0, y2=0,cnt=0,days1,days2;
	
	while (date1head != NULL)
	{
		if (cnt >= 0 && cnt <= 1)d1 = d1 * 10 + date1head->data;
		else if (cnt >= 2 && cnt <= 3)m1 = m1 * 10 + date1head->data;
		else if (cnt >= 4 && cnt <= 7)y1 = y1 * 10 + date1head->data;
	}
	cnt = 0;
	while (date2head != NULL)
	{
		if (cnt >= 0 && cnt <= 1)d2 = d2 * 10 + date2head->data;
		else if (cnt >= 2 && cnt <= 3)m2 = m2 * 10 + date2head->data;
		else if (cnt >= 4 && cnt <= 7)y2 = y2 * 10 + date2head->data;
	}
	if (isValid(d1, m1, y1) && isValid(d2, m2, y2))return -1;
	days1 = getDays(d1, m1, y1);
	days2 = getDays(d2, m2, y2);
	if ((days2 - days1) < 0)return days1 - days2;
	return days2 - days1;
}
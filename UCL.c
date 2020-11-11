# CodeChef
#include<stdio.h>
#include<string.h>
struct team {
    char name[11];
    int points;
    int gd;
};
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        struct team u[4];
        struct team temp;
        for(i=0;i<4;i++)
        {
            u[i].points = 0;
            u[i].gd = 0;
        }
        int num = 1;
        int teamsize=0;
        while(num <= 12)
        {
            char homeTeam[10],awayTeam[10];
            int  homeScore, awayScore;
            scanf("%s%d vs. %d %s",homeTeam,&homeScore,&awayScore,awayTeam);
            if(num==1)
            {
                strcpy(u[0].name,homeTeam);
                u[0].gd = (homeScore - awayScore);
                strcpy(u[1].name,awayTeam);
                u[1].gd = awayScore - homeScore;
                if(homeScore == awayScore)
                {
                    u[0].points=1;
                    u[1].points=1;
                }
                else
                {
                    if(homeScore > awayScore)
                        u[0].points = 3;
                    else
                        u[1].points = 3;
                }
                teamsize = 2;
            }
            else
            {
                int teampos = search(homeTeam,u,teamsize);
                if(teampos == -1)
                {
                    //team not found in array
                    strcpy(u[teamsize].name,homeTeam);
                    u[teamsize].gd += (homeScore - awayScore);
                    if(homeScore == awayScore)
                    {
                        u[teamsize].points += 1;
                    }
                    else
                    {
                        if(homeScore > awayScore)
                            u[teamsize].points+= 3;
                        //else
                            //points[1] += 3;
                    }
                    teamsize++;
                }
                else
                {
                    u[teampos].gd += (homeScore - awayScore);
                    if(homeScore == awayScore)
                    {
                        u[teampos].points+= 1;
                    }
                    else
                    {
                        if(homeScore > awayScore)
                            u[teampos].points+= 3;
                        //else
                            //points[1] += 3;
                    }
                }
                teampos = search(awayTeam,u,teamsize);
                if(teampos == -1)
                {
                    //team not found in array
                    strcpy(u[teamsize].name,awayTeam);
                    u[teamsize].gd += (awayScore-homeScore);
                    if(homeScore == awayScore)
                    {
                        u[teamsize].points+= 1;
                    }
                    else
                    {
                        if(homeScore < awayScore)
                            u[teamsize].points+= 3;
                        //else
                            //points[1] += 3;
                    }
                    teamsize++;
                }
                else
                {
                    u[teampos].gd += (awayScore-homeScore);
                    if(homeScore == awayScore)
                    {
                        u[teampos].points += 1;
                    }
                    else
                    {
                        if(homeScore < awayScore)
                            u[teampos].points += 3;
                        //else
                            //points[1] += 3;
                    }
                }
            }
            num++;
        }
        for(i=1;i<teamsize;i++)
        {
            for(j=0;j<teamsize-i;j++)
            {
                if(u[j].points > u[j+1].points || (u[j].points == u[j+1].points && u[j].gd > u[j+1].gd))
                {
                    temp = u[j];
                    u[j] = u[j+1];
                    u[j+1] = temp;
                }
            }
        }
        printf("%s %s\n",u[3].name,u[2].name);
    }
}
int search(char teams[], struct team t[], int n)
{
    int i;
    for(i=0;i<n;i++)
        if(strcmp(t[i].name,teams)==0)
            return i;
    return -1;
}

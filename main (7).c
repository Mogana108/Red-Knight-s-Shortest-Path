#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct  s_action
{
    int         step;
    int         UL;
    int         UR;
    int         R;
    int         LR;
    int         LL;
    int         L;
}               t_action;

void    ft_impossible()
{
    printf("Impossible");
    exit(0);
}

void    init_action(t_action *action)
{
    action->step = 0;
    action->UL = 0;
    action->UR = 0;
    action->R = 0;
    action->LR = 0;
    action->LL = 0;
    action->L = 0;
}
void    UL(int *i_start, int *j_start, t_action *action, int n)
{
    *i_start -= 2;
    *j_start -= 1;
    if (*j_start < 0)
        ft_impossible();
    action->step += 1;
    action->UL += 1;
}

void    UR(int *i_start, int *j_start, t_action *action, int n)
{
    *i_start -= 2;
    *j_start += 1;
    if (*j_start >= n)
        ft_impossible();
    action->step += 1;
    action->UR += 1;
}

void    R(int *j_start, t_action *action, int n)
{
    *j_start += 2;
    if (*j_start >= n)
        ft_impossible();
    action->step += 1;
    action->R += 1;
}

void    LR(int *i_start, int *j_start, t_action *action, int n)
{
    *i_start += 2;
    *j_start += 1;
    if (*j_start >= n)
        ft_impossible();
    action->step += 1;
    action->LR += 1;
}

void    LL(int *i_start, int *j_start, t_action *action, int n)
{
    *i_start += 2;
    *j_start -= 1;
    if (*j_start < 0)
        ft_impossible();
    action->step += 1;
    action->LL += 1;
}

void    L(int *j_start, t_action *action, int n)
{
    *j_start -= 2;
    if (*j_start < 0)
        ft_impossible();
    action->step += 1;
    action->L += 1;
}

void    print_action(t_action action)
{
    printf("%d\n", action.step);
    while (action.UL--)
        printf("UL ");
    while (action.UR--)
        printf("UR ");
    while (action.R--)
        printf("R ");
    while (action.LR--)
        printf("LR ");
    while (action.LL--)
        printf("LL ");
    while (action.L--)
        printf("L ");
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    //  Print the distance along with the sequence of moves.
    t_action    action;
    int         vertical;
    int         down_move;
   
    init_action(&action);
    vertical = (i_end - i_start > 0) ? i_end - i_start : i_start - i_end;
    if (vertical % 2 == 1)
        ft_impossible();
    while (i_end < i_start)
    {
        if (j_end <= j_start)
            UL(&i_start, &j_start, &action, n);
        else
            UR(&i_start, &j_start, &action, n);
    }
    down_move = vertical / 2 - action.step;
    while (j_end - down_move > j_start)
        R(&j_start, &action, n);
    while (i_end > i_start)
    {
        if (j_end >= j_start)
            LR(&i_start, &j_start, &action, n);
        else
            LL(&i_start, &j_start, &action, n);
    }
    while (j_end < j_start)
        L(&j_start, &action, n);
    if (j_end != j_start)
        ft_impossible();
    print_action(action);
}

int main() {
    int n;
    scanf("%i", &n);
    int i_start;
    int j_start;
    int i_end;
    int j_end;
    scanf("%i %i %i %i", &i_start, &j_start, &i_end, &j_end);
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}

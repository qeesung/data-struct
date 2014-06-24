/*
 * =====================================================================================
 *
 *       Filename:  maze.h
 *
 *    Description:  This is the Header file about the maze
 *
 *        Version:  1.0
 *        Created:  2014年06月24日 03时29分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (), 1245712564@qq.com
 *   Organization:  STAY HUNGRY STAY FOOLISH
 *
 * =====================================================================================
 */

#ifndef _MAZE_H
#define _MAZE_H

#define MAZE_SIZE 9

struct seat {
	/*  define x-y zuobiao */
	int x;
	int y;
};				/* ----------  end of struct Seat  ---------- */

typedef struct seat * Seat;


struct maze_node {
	Seat my_seat;/*  this is the pointer seat */
	int visited;/*  this will maek if this point has been visited */
	int roate;/*  this mark if this pointer is can be passed */
};				/* ----------  end of struct maze_node  ---------- */

typedef struct maze_node *  Maze_node;

	
void Init_Maze(struct maze_node my_maze[MAZE_SIZE][MAZE_SIZE]);/*  return a maze[][] */
void Mark(Maze_node my_maze_node);
seat Next_Position(Maze_node my_maze_node);
int Pass(Maze_node my_maze_node);

#endif

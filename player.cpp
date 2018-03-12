#include "player.hpp"
#include <unistd.h>



/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    //usleep(15000000);
    othello = new Board();  //creates board with 4 center pieces

    mine = side;
    if (mine == BLACK)
    {
      yours = WHITE;
    }
    else
    {
      yours = BLACK;
    }
    testingMinimax = true;


    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
  // Delete dynamically allocated objects to clean up garbage
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */

int Player::MiniMax(Move *opponentsMove, int msLeft, Move &bestmove)
{

    othello->doMove(opponentsMove, yours);
    int layer = max_depth;
    return MiniMaxOneLayer(opponentsMove, layer, mine, msLeft, bestmove);
}


int Player::MiniMaxOneLayer(Move *opponentsMove, int layer, Side side, int msLeft, Move &bestmove)
{

 // collect vector from getMoves in pointer and delete the pointer each time




  if (layer == 0)
  /*{
    Side temp_side;
    if(side == mine)
    {
        temp_side = yours;
    }
    else
    {
        temp_side = mine;
    }*/
    return othello->getBoardScore(side);
    /*if(side == BLACK)
    {
        return othello->countBlack();
    }
    else
    {
        return othello->countWhite();
    }*/

    //return SimplePlayer(opponentsMove, msLeft);   //returns the best move
  }

  else
  {
    int best;
    //Move* best_move = new Move(0,0);
    int best_i = 0;

    //assigning side:
    Side temp_side;
    if(side == mine)
    {
        temp_side = yours;
    }
    else
    {
        temp_side = mine;
    }
    int current_score;
    vector <Move*> all_moves = othello->getMoves(opponentsMove, side);
    //Move* current_move = new Move(0,0);
    for (unsigned int i = 0; i < all_moves.size(); i++)
    {
        int x = all_moves[i]->getX();
        int y = all_moves[i]->getY();

     cout<<"Possible Move x: " << x << " y: " << y<<endl;
      Board *temp = othello->copy();
      temp->doMove(all_moves[i],side);
      layer--;
      current_score = MiniMaxOneLayer(all_moves[i], layer, temp_side, msLeft, bestmove);
      //int current_score = temp->checkScore(current_move);
      if (side == BLACK)
      {
        best = -1000;
        if (current_score > best)
        {
          best = current_score;
          if (layer == max_depth -1)
          {
               best_i = i;
          }

          //best_move = current_move;
        }
      }
      else
      {
        best = 1000;
        if (current_score < best)
        {
          best = current_score;
          if (layer == max_depth -1)
          {
               best_i = i;
          }

          //best_move = current_move;
        }
      }
      if (layer == max_depth -1)
      {
        bestmove = *all_moves[best_i];
      }
    }
    //return current_move;

    return current_score;
  }
}



Move *Player::SimplePlayer(Move *opponentsMove, int msLeft) {
  othello->doMove(opponentsMove, yours);
  Move *move = new Move(0, 0);
  Move *maxMove = nullptr;
  for (int i = 0; i < 8; i ++)
  {
    for (int j = 0; j < 8; j ++)
    {
      move ->setX(i);
      move ->setY(j);
      if (othello->checkMove(move, mine))
      {
        if (maxMove == nullptr ||
          othello->checkScore(move) > othello->checkScore(maxMove))
        {
          maxMove = move;
        }
      }
    }
  }
  return maxMove;
}

Move *Player::RandomHeuristic(Move *opponentsMove, int msLeft) {
  othello->doMove(opponentsMove, yours);
  Move *move = new Move(0, 0);
  for (int i = 0; i < 8; i ++)
  {
    for (int j = 0; j < 8; j ++)
    {
      move ->setX(i);
      move ->setY(j);
      if (othello->checkMove(move, mine))
      {
        othello->doMove(move, mine);
        return move;
      }
    }
}
}

Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
    Move* best = new Move(0,0);

     MiniMax(opponentsMove, msLeft, *best);
     return best;
     // return SimplePlayer(opponentsMove, msLeft);
     // return RandomHeuristic(opponentsMove, msLeft);

}

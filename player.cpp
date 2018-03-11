#include "player.hpp"


/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
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
    testingMinimax = false;


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

Move *Player::MiniMax(Move *opponentsMove, int msLeft)
{
    int layer = max_depth;
    return MiniMaxOneLayer(opponentMove, layer);
}


Move *Player::MiniMaxOneLayer(Move *opponentsMove, int layer, Side side) {

 // collect vector from getMoves in pointer and delete the pointer each time

  if (layer == 0)
  {
    return SimplePlayer(opponentsMove, msLeft);   //returns the best move
  }

  else
  {
    int best = -1000;
    Move* best_move = nullptr;
    vector <Move*> *all_moves = othello->getMoves(opponentMove, yours);
    for (int i = 0; i < all_moves.size(); i++)
    {
      Move* current_move = MiniMaxOneLayer((all_moves[i], layer-1, yours);
      int current_score = othello->checkScore(current_move);
      if (current_score > best)
      {
        best = current_score;
        best_move = current_move;
      }
    }
    return current_move;
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

     return MiniMax(opponentsMove, msLeft);
     // return SimplePlayer(opponentsMove, msLeft);
     // return RandomHeuristic(opponentsMove, msLeft);

}

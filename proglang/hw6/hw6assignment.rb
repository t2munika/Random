# University of Washington, Programming Languages, Homework 6, hw6runner.rb

# This is the only file you turn in, so do not modify the other files as
# part of your solution.

class MyPiece < Piece
  # The constant All_My_Pieces should be declared here
  All_My_Pieces = All_Pieces.concat(
    [rotations([[0, 0], [1, 0], [0, 1], [1, 1], [2, 1]]), # square with tail
     [[[0, 0], [-2, 0], [-1, 0], [1, 0], [2, 0]],        # extra-long (only needs two)
      [[0, 0], [0, -2], [0, -1], [0, 1], [0, 2]]],
     rotations([[0, 0], [1, 0], [0, 1]])])

  # your enhancements here
  Cheat = [[[0, 0]]]

  def self.cheat(board)
    MyPiece.new(Cheat, board)
  end

  # override class method to choose the next piece from 
  # all ten pieces instead of the classic seven.
  def self.next_piece (board)
    MyPiece.new(All_My_Pieces.sample, board)
  end
end

class MyBoard < Board
  # your enhancements here
  def initialize (game)
    super(game)
    @is_cheat_turn = false
  end

  # rotates the current piece clockwise
  def rotate_upsidedown
    if !game_over? and @game.is_running?
      @current_block.move(0, 0, 2)
    end
    draw
  end

  def cheat
    if @score >= 100 and !game_over? and @game.is_running? and !@is_cheat_turn
      @score = @score - 100
      @is_cheat_turn = true
    end
  end

  def next_piece
    if @is_cheat_turn
      @current_block = MyPiece.cheat(self)
      @is_cheat_turn = false
      @current_pos = nil
    else
      super
    end
  end

  # gets the information from the current piece about where it is and uses this
  # to store the piece on the board itself.  Then calls remove_filled.
  def store_current
    locations = @current_block.current_rotation
    displacement = @current_block.position
    (0..locations.length-1).each{|index| 
      current = locations[index];
      @grid[current[1]+displacement[1]][current[0]+displacement[0]] = 
      @current_pos[index]
    }
    remove_filled
    @delay = [@delay - 2, 80].max
  end
end

class MyTetris < Tetris
  # creates a canvas and the customized board that interacts with it
  def set_board
    @canvas = TetrisCanvas.new
    @board = MyBoard.new(self)
    @canvas.place(@board.block_size * @board.num_rows + 3,
                  @board.block_size * @board.num_columns + 6, 24, 80)
    @board.draw
  end

  def key_bindings
    super
    @root.bind('u', proc {@board.rotate_upsidedown})
    @root.bind('c', proc {@board.cheat})
  end
end

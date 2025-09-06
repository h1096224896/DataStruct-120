import tkinter as tk
import random
import time
from tkinter import messagebox, simpledialog


class SnakeGame:

    def __init__(self, root):
        self.root = root
        self.root.title("🐍 贪吃蛇游戏")
        self.root.resizable(False, False)

        # 游戏配置
        self.GRID_SIZE = 20
        self.CANVAS_WIDTH = 600
        self.CANVAS_HEIGHT = 400
        self.SPEED = 150  # 毫秒，控制游戏速度
        self.DIRECTIONS = {
            "Up": (0, -1),
            "Down": (0, 1),
            "Left": (-1, 0),
            "Right": (1, 0),
        }

        # 初始化游戏状态
        self.score = 0
        self.high_score = 0
        self.game_running = False
        self.paused = False
        self.snake = [(5, 5), (4, 5), (3, 5)]  # 蛇身，第一个是头部
        self.food = None
        self.direction = "Right"
        self.next_direction = "Right"

        # 创建UI界面
        self.create_ui()

        # 绑定键盘事件
        self.root.bind("<KeyPress>", self.on_key_press)

        # 放置第一个食物
        self.place_food()

    def create_ui(self):
        """创建用户界面"""
        # 标题
        title_frame = tk.Frame(self.root, bg="#2c3e50", padx=10, pady=10)
        title_frame.pack(fill=tk.X)

        title_label = tk.Label(
            title_frame,
            text="🐍 贪吃蛇游戏 🐍",
            font=("微软雅黑", 20, "bold"),
            fg="white",
            bg="#2c3e50",
        )
        title_label.pack()

        # 分数显示区域
        score_frame = tk.Frame(self.root, bg="#34495e", padx=10, pady=5)
        score_frame.pack(fill=tk.X)

        self.score_label = tk.Label(
            score_frame,
            text=f"分数: {self.score}",
            font=("Arial", 14, "bold"),
            fg="white",
            bg="#34495e",
        )
        self.score_label.pack(side=tk.LEFT, padx=10)

        self.high_score_label = tk.Label(
            score_frame,
            text=f"最高分: {self.high_score}",
            font=("Arial", 14, "bold"),
            fg="yellow",
            bg="#34495e",
        )
        self.high_score_label.pack(side=tk.RIGHT, padx=10)

        # 游戏画布
        self.canvas = tk.Canvas(
            self.root,
            width=self.CANVAS_WIDTH,
            height=self.CANVAS_HEIGHT,
            bg="#1e1e1e",
            highlightthickness=2,
            highlightbackground="#3498db",
        )
        self.canvas.pack(padx=10, pady=10)

        # 控制按钮区域
        button_frame = tk.Frame(self.root, bg="#ecf0f1", padx=10, pady=10)
        button_frame.pack(fill=tk.X)

        button_style = {
            "font": ("Arial", 12, "bold"),
            "width": 12,
            "height": 2,
            "bd": 0,
            "cursor": "hand2",
        }

        self.start_button = tk.Button(
            button_frame,
            text="开始游戏",
            bg="#27ae60",
            fg="white",
            command=self.start_game,
            **button_style,
        )
        self.start_button.pack(side=tk.LEFT, padx=5)

        self.pause_button = tk.Button(
            button_frame,
            text="暂停/继续",
            bg="#f39c12",
            fg="white",
            command=self.toggle_pause,
            state=tk.DISABLED,
            **button_style,
        )
        self.pause_button.pack(side=tk.LEFT, padx=5)

        self.restart_button = tk.Button(
            button_frame,
            text="重新开始",
            bg="#e74c3c",
            fg="white",
            command=self.restart_game,
            state=tk.DISABLED,
            **button_style,
        )
        self.restart_button.pack(side=tk.LEFT, padx=5)

        # 游戏说明
        instructions_frame = tk.Frame(self.root, bg="#bdc3c7", padx=10, pady=10)
        instructions_frame.pack(fill=tk.X, padx=10, pady=(0, 10))

        instructions = tk.Label(
            instructions_frame,
            text="操作说明: ←↑↓→ 方向键控制移动 | P 键暂停/继续 | R 键重新开始",
            font=("Arial", 10),
            fg="#2c3e50",
            bg="#bdc3c7",
            wraplength=580,
        )
        instructions.pack()

    def place_food(self):
        """在随机位置放置食物"""
        while True:
            x = random.randint(0, (self.CANVAS_WIDTH // self.GRID_SIZE) - 1)
            y = random.randint(0, (self.CANVAS_HEIGHT // self.GRID_SIZE) - 1)
            food_pos = (x, y)

            # 确保食物不在蛇身上
            if food_pos not in self.snake:
                self.food = food_pos
                break

    def draw_game(self):
        """绘制游戏画面"""
        # 清空画布
        self.canvas.delete("all")

        # 绘制网格背景（可选）
        for i in range(0, self.CANVAS_WIDTH, self.GRID_SIZE):
            for j in range(0, self.CANVAS_HEIGHT, self.GRID_SIZE):
                if (i // self.GRID_SIZE + j // self.GRID_SIZE) % 2 == 0:
                    self.canvas.create_rectangle(
                        i,
                        j,
                        i + self.GRID_SIZE,
                        j + self.GRID_SIZE,
                        fill="#2d2d2d",
                        outline="",
                    )

        # 绘制食物
        if self.food:
            x, y = self.food
            self.canvas.create_oval(
                x * self.GRID_SIZE + 2,
                y * self.GRID_SIZE + 2,
                (x + 1) * self.GRID_SIZE - 2,
                (y + 1) * self.GRID_SIZE - 2,
                fill="#e74c3c",
                outline="#c0392b",
                width=2,
            )

        # 绘制蛇
        for i, (x, y) in enumerate(self.snake):
            if i == 0:  # 蛇头
                color = "#2ecc71"
                outline = "#27ae60"
            else:  # 蛇身
                # 渐变效果
                green_value = max(180 - i * 5, 100)
                color = f"#{green_value:02x}ff{green_value:02x}"
                outline = "#27ae60"

            self.canvas.create_rectangle(
                x * self.GRID_SIZE,
                y * self.GRID_SIZE,
                (x + 1) * self.GRID_SIZE,
                (y + 1) * self.GRID_SIZE,
                fill=color,
                outline=outline,
                width=2,
            )

            # 在蛇头上添加眼睛
            if i == 0:
                eye_size = self.GRID_SIZE // 5
                dir_x, dir_y = self.DIRECTIONS[self.direction]

                # 根据方向调整眼睛位置
                if self.direction == "Right":
                    self.canvas.create_oval(
                        (x + 0.7) * self.GRID_SIZE - eye_size,
                        (y + 0.3) * self.GRID_SIZE - eye_size,
                        (x + 0.7) * self.GRID_SIZE + eye_size,
                        (y + 0.3) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )
                    self.canvas.create_oval(
                        (x + 0.7) * self.GRID_SIZE - eye_size,
                        (y + 0.7) * self.GRID_SIZE - eye_size,
                        (x + 0.7) * self.GRID_SIZE + eye_size,
                        (y + 0.7) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )
                elif self.direction == "Left":
                    self.canvas.create_oval(
                        (x + 0.3) * self.GRID_SIZE - eye_size,
                        (y + 0.3) * self.GRID_SIZE - eye_size,
                        (x + 0.3) * self.GRID_SIZE + eye_size,
                        (y + 0.3) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )
                    self.canvas.create_oval(
                        (x + 0.3) * self.GRID_SIZE - eye_size,
                        (y + 0.7) * self.GRID_SIZE - eye_size,
                        (x + 0.3) * self.GRID_SIZE + eye_size,
                        (y + 0.7) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )
                elif self.direction == "Up":
                    self.canvas.create_oval(
                        (x + 0.3) * self.GRID_SIZE - eye_size,
                        (y + 0.3) * self.GRID_SIZE - eye_size,
                        (x + 0.3) * self.GRID_SIZE + eye_size,
                        (y + 0.3) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )
                    self.canvas.create_oval(
                        (x + 0.7) * self.GRID_SIZE - eye_size,
                        (y + 0.3) * self.GRID_SIZE - eye_size,
                        (x + 0.7) * self.GRID_SIZE + eye_size,
                        (y + 0.3) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )
                elif self.direction == "Down":
                    self.canvas.create_oval(
                        (x + 0.3) * self.GRID_SIZE - eye_size,
                        (y + 0.7) * self.GRID_SIZE - eye_size,
                        (x + 0.3) * self.GRID_SIZE + eye_size,
                        (y + 0.7) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )
                    self.canvas.create_oval(
                        (x + 0.7) * self.GRID_SIZE - eye_size,
                        (y + 0.7) * self.GRID_SIZE - eye_size,
                        (x + 0.7) * self.GRID_SIZE + eye_size,
                        (y + 0.7) * self.GRID_SIZE + eye_size,
                        fill="black",
                    )

    def move_snake(self):
        """移动蛇"""
        if not self.game_running or self.paused:
            return True

        # 更新方向
        self.direction = self.next_direction
        dx, dy = self.DIRECTIONS[self.direction]

        # 计算新头部位置
        head_x, head_y = self.snake[0]
        new_head = (head_x + dx, head_y + dy)

        # 检查碰撞
        if self.check_collision(new_head):
            self.game_over()
            return False

        # 添加新头部
        self.snake.insert(0, new_head)

        # 检查是否吃到食物
        if new_head == self.food:
            self.score += 10
            self.score_label.config(text=f"分数: {self.score}")
            self.place_food()
            # 每吃5个食物，速度加快一点
            if self.score % 50 == 0 and self.SPEED > 50:
                self.SPEED = max(50, self.SPEED - 10)
        else:
            # 没有吃到食物，移除尾部
            self.snake.pop()

        return True

    def check_collision(self, position):
        """检查是否发生碰撞"""
        x, y = position

        # 检查边界碰撞
        if (
            x < 0
            or x >= self.CANVAS_WIDTH // self.GRID_SIZE
            or y < 0
            or y >= self.CANVAS_HEIGHT // self.GRID_SIZE
        ):
            return True

        # 检查自身碰撞（除了尾部，因为尾部会移动）
        if position in self.snake[:-1]:
            return True

        return False

    def game_loop(self):
        """游戏主循环"""
        if self.game_running and not self.paused:
            if self.move_snake():
                self.draw_game()
                self.root.after(self.SPEED, self.game_loop)
            else:
                return
        elif self.game_running:
            # 如果暂停了，稍后再检查
            self.root.after(100, self.game_loop)

    def start_game(self):
        """开始游戏"""
        if not self.game_running:
            self.game_running = True
            self.paused = False
            self.start_button.config(state=tk.DISABLED)
            self.pause_button.config(state=tk.NORMAL)
            self.restart_button.config(state=tk.NORMAL)
            self.game_loop()

    def toggle_pause(self):
        """暂停/继续游戏"""
        if self.game_running:
            self.paused = not self.paused
            if not self.paused:
                self.game_loop()

    def restart_game(self):
        """重新开始游戏"""
        self.score = 0
        self.SPEED = 150
        self.snake = [(5, 5), (4, 5), (3, 5)]
        self.direction = "Right"
        self.next_direction = "Right"
        self.paused = False
        self.place_food()

        self.score_label.config(text=f"分数: {self.score}")
        self.draw_game()

        if not self.game_running:
            self.start_button.config(state=tk.NORMAL)
            self.pause_button.config(state=tk.DISABLED)
            self.restart_button.config(state=tk.DISABLED)
        else:
            self.game_loop()

    def game_over(self):
        """游戏结束"""
        self.game_running = False

        # 更新最高分
        if self.score > self.high_score:
            self.high_score = self.score
            self.high_score_label.config(text=f"最高分: {self.high_score}")

        # 显示游戏结束对话框
        response = messagebox.askyesno(
            "游戏结束",
            f"游戏结束！你的得分是: {self.score}\n最高分: {self.high_score}\n\n是否重新开始？",
        )

        if response:
            self.restart_game()
        else:
            self.start_button.config(state=tk.NORMAL)
            self.pause_button.config(state=tk.DISABLED)
            self.restart_button.config(state=tk.DISABLED)

    def on_key_press(self, event):
        """处理键盘事件"""
        key = event.keysym

        # 方向控制
        if key in ["Up", "Down", "Left", "Right"]:
            # 防止直接反向移动
            if (
                (key == "Up" and self.direction != "Down")
                or (key == "Down" and self.direction != "Up")
                or (key == "Left" and self.direction != "Right")
                or (key == "Right" and self.direction != "Left")
            ):
                self.next_direction = key

        # 快捷键
        elif key.lower() == "p":  # 暂停/继续
            self.toggle_pause()
        elif key.lower() == "r":  # 重新开始
            self.restart_game()
        elif key.lower() == "s" and not self.game_running:  # 开始游戏
            self.start_game()


def main():
    """主函数"""
    root = tk.Tk()
    game = SnakeGame(root)
    root.mainloop()


if __name__ == "__main__":
    main()

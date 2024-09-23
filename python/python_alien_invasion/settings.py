class Settings:
    def __init__(self):
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (230, 230, 230)

        # 飞船的速度
        self.ship_speed = 1.5

        # 子弹设置
        self.bullet_speed = 2.0
        self.bullet_width = 3
        self.bullet_height = 15
        self.bullet_color = (60, 60, 60)

        # 外星舰队
        self.alien_speed = 1.0
        self.fleet_drop_speed = 10
        # fleet_direction为1则表示向右移动，-1表示向左
        self.fleet_direction = 1

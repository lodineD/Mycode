import pygame


class Ship:
    def __init__(self, ai_game):
        """初始化飞船和其初始位置"""
        self.screen = ai_game.screen
        self.settings = ai_game.settings
        self.screen_rect = ai_game.screen.get_rect()

        # 加载飞船图形，并用矩形处理（矩形处理简单）
        # 加载背景图
        # self.image = pygame.image.load('images/1067431136.bmp')
        self.ship = pygame.image.load('images/ship_60.bmp')
        # self.rect = self.image.get_rect()
        self.rect_ship = self.ship.get_rect()

        # 每个飞船都放在屏幕底部的中间
        self.rect_ship.midbottom = self.screen_rect.midbottom

        self.x = float(self.rect_ship.x)

        # 开始飞船不动
        self.moving_right = False
        self.moving_left = False

    def update(self):
        """根据移动标志调整飞船的位置"""
        if self.moving_right:
            if self.moving_right and self.rect_ship.right < self.screen_rect.right:
                self.x += self.settings.ship_speed
        if self.moving_left:
            if self.moving_left and self.rect_ship.left > 0:
                self.x -= self.settings.ship_speed

        self.rect_ship.x = self.x

    def blitme(self):
        """在指定位置绘制飞船"""
        # self.screen.blit(self.image, self.rect)
        self.screen.blit(self.ship, self.rect_ship)

# opengl-learn
learn opengl



## 1 画点



## 2 画线 多边形 三角形



## 3 keyboard 键盘交互

`glutKeyboardFunc`

通过wsad按键调整矩形位置



## 4  鼠标交互

鼠标左键点击哪个位置，矩形就变化到哪个位置



## 5  DDA数值微分线段算法

之前画线本质上是**一个一个像素点连接起来**，所以没有笔直的线段，放大看会有粗糙的现象,像素点有偏差

DDA 数值微分法

+ Δx为 终点x - 起点x		  Δy为 终点y - 起点y
+ 当Δx > Δy, 把x作为主方向: `steps = |Δx| > |Δy|? Δx: Δy`
+ 当Δx < Δy, 把y作为主方向: `steps = |Δx| > |Δy|? Δx: Δy`
+ `stepX = Δx / steps`                     `stepY = Δy / steps`
+ 按照step一个一个点画出来, x一次增加stepX, y一次增加stepY



## 6 Bresenham 直线算法

假设x方向占优，x每次步进为1

+ 第一个点 (Xk, Yk)

+ 第二个点(X(k+1), du或者dl ),   y的位置和像素点有所偏差(小数), 记录y上面一点的像素点位置和当前点距离为du, 下面为dl
  + 设直线 `y = mX(k+1) + b`
  + **当 du > dl, 选择下面这个点**
  + **当 du < dl, 选择上面这个点**
  + 设当前点为y，上面一点为y(k+1), 下面一点为y(k)
  + dl = y - yk = mX(k+1) + b - y(k)
  + du = y(k+1) - y = y(k+1) - mX(k+1) - b
  + dl - du = mx(k+1) + b - y(k) - y(k+1) + mX(k+1) +b
    + = 2mx(k+1) - y(k) - y(k+1) + 2b
    + = 2m*x(k+1) - 2y(k) + 2b - 1
  + 令 P(k) = Δx(dl - du)
    + = `Δx*2mx(k+1) - 2Δx*y(k) + Δx*(2b - 1)`
    + 因为m为斜率，所以 `Δx*(Δy/Δx)2x(k+1) - 2Δx*y(k) + Δx*(2b - 1)`
    + = `2Δyx(k+1) - 2Δx*y(k) + Δx*(2b - 1)` 
    + 因为x(k+1) = x(k) + 1, 所以: `2Δyx(k) - 2Δx*y(k) + 2Δy + Δx*(2b - 1)` 
    + 省略常数项， 写成: `2Δyx(k) - 2Δx*y(k) + C`
  + 当P(k) > 0时， dl > du, 选上面点
  + 当P(k) < 0时， dl < du, 选下面点
  + P(k+1) = 2Δyx(k+1) - 2Δx*y(k+1) + C
  + P(k+1) - P(k) = 2Δy(x(k+1) - x(k)) - 2Δx(y(k+1) - y(k))
    + 因为前提条件x方向占优, 所以： 2Δy * 1 - 2Δx(y(k+1) - y(k))
  + P(k+1) = 2Δy * 1 - 2Δx(y(k+1) - y(k)) + P(k),  是一个**递推的公式**，可以根据上一次的结果推下一次结果
  + 计算p1的方法:
    + **如果p0 > 0** ,由于选上面那个点，所以y(k+1) - y(k) = 1，得出： **p1 = p0 + 2Δy - 2Δx**
    + **如果p0 < 0** ,由于选下面那个点，所以y(k+1) - y(k) = 0，得出： **p1 = p0 + 2Δy** 



​	算法步骤:

1. 输入 (x1, y1)  (xn, yn)
2. dx = xn - x1            dy = yn - y1
3. 2dx                2dy
4. p0 = 2dy - dx
5. 循环
   1. 如果P(k) > 0 ,选上面点(x(k+1), y(k+1))  **p(k+1) = p(k) + 2dy - 2dx**
   2. 如果P(k) < 0, 选下面点(x(k+1), yk)         **p(k+1) = p(k) + 2dy**



## 7 中点画线法

假设x方向占优， 即 x(i+1) = x(i) + 1

假设直线公式`y = mx + b`, 则`y - mx - b = 0` , ` m = Δx / Δy`, `b = y1 - mx1`

令 `F(x, y) = y - mx - b`

可以得到， 一个点(x, y)：

+ (x, y)在F(x, y)直线上， `F(x, y) = 0`
+ (x, y)在F(x, y)的上面， `F(x, y) > 0`
+ (x, y)在F(x, y)的下面， `F(x, y) < 0`

假设直线所在网格的中点为d(i), 则坐标为 (x(i), y(i) + 0.5)

把中点d(i)的代入F(x, y) 中， `y(i) + 0.5 - mx(i) - b`

d(i+1)带入F(x,y)中, `y(i+1) + 0.5 - m(x(i) + 1) - b` = `y(i+1) + 0.5 - mx(i) - b - m`

如果di > 0，说明中点在直线上面, 应该选择网格下面的点

+ y(i+1) = y(i)  =>     F(d(i+1)) = y(i) + 0.5 - mx(i) - b - m`  = `F(d(i)) - m` 
+ 综上所述 F(d(i+1)) = F(di) - m

如果di < 0，说明中点在直线下面, 应该选择网格上面的点

+ y(i+1) = y(i) +1  => F(d(i+1)) = y(i) + 1 + 0.5 - mx(i) - b - m`  = `F(d(i)) + 1 - m` 
+ 综上所述 F(d(i+1)) = F(di) + 1 - m





算法步骤：

1. d1 = F(x1, y1 + 0.5) = y1 + 0.5 - mx1 - b
2. 循环
   1. x += 1
   2. 当di > 0
      1. d(i+1) += -m
      2. y 不变
   3. 当di < 0
      1. d(i+1) += 1 - m
      2. y += 1



## 8 二维图形变换1(平移、旋转、缩放)

平移:

​	`x1 = x + tx`

​	`y1 = y + tx`



旋转:

r为点到原点的长度

设`cosθ = x/r` => `x = r*cosθ`

设`sinθ = y/r` => `y = r*sinθ`

沿着原点旋转情况下, 新点为(x1, y1)

则 `cos(θ+θ1) = x1 / r`  =>  `x1 = r * cos(θ+θ1)` => `x1 = rcos(θ)cos(θ1) - rsin(θ)*sin(θ1)` => `x1 = xcos(θ1) - ysin(θ1)`

则 `sin(θ+θ1) = y1 / r` => `y1 = r * sin(θ+θ1)` => `y1 = rcos(θ)sin(θ1) + rsin(θ)cos(θ1)` => `y1 = xsin(θ1) + ycos(θ1)`

所以只需要知道起始点和角度θ1可以算出新的点



问题： 如果不是绕着原点旋转怎么办?

答：把坐标系平移到中心点的位置，旋转完毕后在平移回去

得出平移后坐标点, xr,yr为任意旋转点， (θ)为旋转角度:

+ x1 = xr + (x - xr)cos(θ) - (y - yr)sin(θ)
+ y1 = yr + (x-xr)sin(θ) + (y-yr)cos(θ)



缩放:

sx sy为x和y方向的缩放因子

`x1 = x * sx`

`y1 = y * sy`



## 9 二维图形变化2 - 矩阵形式

加法运算:

行和列相等才能相加

$\begin{bmatrix}
1 & 2 \\
3 & 4
\end{bmatrix}$ + $\begin{bmatrix}
5 & 6 \\
7 & 8
\end{bmatrix}$ = $\begin{bmatrix}
6 & 8 \\
10 & 12
\end{bmatrix}$



乘法运算:

后面的行数要等于前面的列数才能相乘

P = $\begin{bmatrix}
1 & 2 \\
3 & 4
\end{bmatrix}$

T = $\begin{bmatrix}
5 & 6 \\
7 & 8
\end{bmatrix}$

PxT = $\begin{bmatrix}
1*5+2*7 & 1*6+2*8 \\
3*5+4*7 & 3*6+4*8
\end{bmatrix}$ = $\begin{bmatrix}
19 & 22 \\
43 & 50
\end{bmatrix}$



对于平移:

​	`x· = x + tx`

​	`y· = y + tx`

假设 原来坐标P = $\begin{bmatrix}
x \\
y
\end{bmatrix}$ , 平移后的坐标 P· = $\begin{bmatrix}
x· \\
y·
\end{bmatrix}$, 平移的量T = $\begin{bmatrix}
tx \\
ty
\end{bmatrix}$

矩阵表示 P· = P + T



对于旋转:

+ x· = xcos(θ1) - ysin(θ1)
+ y· = xsin(θ1) + ycos(θ1）

假设 原来坐标P = $\begin{bmatrix}
x \\
y
\end{bmatrix}$ , 旋转后的坐标 P· = $\begin{bmatrix}
x· \\
y·
\end{bmatrix}$, 旋转的量R = $\begin{bmatrix}
cosθ & -sinθ \\
sinθ & cosθ
\end{bmatrix}$

矩阵表示P· = R * P = $\begin{bmatrix}
xcosθ - ysinθ \\
ysinθ + ycosθ
\end{bmatrix}$



对于缩放:

sx sy为x和y方向的缩放因子

`x1 = x * sx`

`y1 = y * sy`

假设 原来坐标P = $\begin{bmatrix}
x \\
y
\end{bmatrix}$ , 缩放后的坐标 P· = $\begin{bmatrix}
x· \\
y·
\end{bmatrix}$, 缩放的量R = $\begin{bmatrix}
sx & 0 \\
0 & sy
\end{bmatrix}$

矩阵表示为 P· = S * P = $\begin{bmatrix}
x*sx \\
y*sy
\end{bmatrix}$

平移函数:`glTranslatef(tx, ty, tz)`

旋转函数: `glRotatef（rx, ry, rz）`

缩放函数: `glScalf(sx, sy, sz)`



## 10二维图形变换3 - 齐次坐标下矩阵形式

使用齐次坐标

+ 平移 p· = T(tx, ty) P:

  $\begin{bmatrix}
  x· \\
  y· \\ 1 \end{bmatrix}$ = $\begin{bmatrix}
  1 & 0 & tx \\
  0 & 1 & ty \\ 0 & 0 & 1
  \end{bmatrix}$ * $\begin{bmatrix}
  x \\
  y \\ 1
  \end{bmatrix}$ = $\begin{bmatrix}
  x + tx \\
  y + ty \\ 1
  \end{bmatrix}$

  

+ 旋转 p· = R(θ)*P:

  $\begin{bmatrix}
  x· \\
  y· \\ 1 \end{bmatrix}$ = $\begin{bmatrix}
  cosθ & -sinθ & 0 \\
  sinθ & cosθ & 0 \\ 0 & 0 & 1
  \end{bmatrix}$ * $\begin{bmatrix}
  x \\
  y \\ 1
  \end{bmatrix}$ = $\begin{bmatrix}
  xcosθ -ysinθ \\
  xsinθ + ycosθ \\ 1
  \end{bmatrix}$

  

+ 缩放 p· = S(sx, sy)*P:

  $\begin{bmatrix}
  x· \\
  y· \\ 1 \end{bmatrix}$ = $\begin{bmatrix}
  sx & 0 & 0 \\
  0 & sy & 0 \\ 0 & 0 & 1
  \end{bmatrix}$ * $\begin{bmatrix}
  x \\
  y \\ 1
  \end{bmatrix}$ = $\begin{bmatrix}
  sx * x \\
  sy * y \\ 1
  \end{bmatrix}$



以上可以统一写成: `p· = M * P` =  $\begin{bmatrix}
a & b & |& m \\
c & d & | & n \\-&-&-&-\\ 0 & 0 & | & s
\end{bmatrix}$ * $\begin{bmatrix}
x \\
y \\ 1
\end{bmatrix}$ 

右上角2 * 1 $\begin{bmatrix}
m \\
n \\ 
\end{bmatrix}$  描述**平移**

左上角2 * 2$\begin{bmatrix}
a & b \\
c & d \\ 
\end{bmatrix}$ 描述**旋转、缩放**

右下角的$\begin{bmatrix}
s \\
\end{bmatrix}$ 一般为1， 若不为1则对图形作整体缩放。



二维复合变换:

+ 复合平移

若经过M1、M2变换

P· = M2(M1 * P) = M2 * M1 * P = M * P

假设经过T1、T2变换，T1 = $\begin{bmatrix}
1 & 0 & tx1 \\
0 & 1 & ty1 \\ 0 & 0 & 1
\end{bmatrix}$ , T2 = $\begin{bmatrix}
1 & 0 & tx2 \\
0 & 1 & ty2 \\ 0 & 0 & 1
\end{bmatrix}$

T = T2 * T1 *P = $\begin{bmatrix}
1 & 0 & tx1 \\
0 & 1 & ty1 \\ 0 & 0 & 1
\end{bmatrix}$ * $\begin{bmatrix}
1 & 0 & tx2 \\
0 & 1 & ty2 \\ 0 & 0 & 1
\end{bmatrix}$ * $\begin{bmatrix}
x \\
y \\ 1
\end{bmatrix}$ = 

$\begin{bmatrix}
1 & 0 & tx1 + tx2 \\
0 & 1 & ty1 + ty2 \\ 0 & 0 & 1
\end{bmatrix}$ * $\begin{bmatrix}
x \\
y \\ 1
\end{bmatrix}$



+ 复合旋转

若经过R1、R2旋转

R1 = $\begin{bmatrix}
cosθ1 & -sinθ1 & 0 \\
sinθ1 & cosθ1 & 0 \\ 0 & 0 & 1
\end{bmatrix}$ R2 = $\begin{bmatrix}
cosθ2 & -sinθ2 & 0 \\
sinθ2 & cosθ2 & 0 \\ 0 & 0 & 1
\end{bmatrix}$

P· = R2 * R1 * P = R(θ1 + θ2) * P

 

+ 复合二维缩放

若经过S1、S2缩放

S1 = $\begin{bmatrix}
Sx1 & 0 & 0 \\
0 & Sy1 & 0 \\ 0 & 0 & 1
\end{bmatrix}$ S2 = $\begin{bmatrix}
 Sx2 & 0 & 0 \\
0 & Sy2 & 0 \\ 0 & 0 & 1
\end{bmatrix}$

#### P· = S2 * S1 * P = $\begin{bmatrix}
 Sx1 * Sx2 & 0 & 0 \\
0 & Sy1 * Sy2 & 0 \\ 0 & 0 & 1
\end{bmatrix}$ * $\begin{bmatrix}
x \\
y \\ 1
\end{bmatrix}$



还可以不同操作的复合

为什么需要复合, 因为比如绕着非原点(Xr, Yr)旋转，那么需要：

1. 先把旋转点平移到坐标中心，T1
2. 进行旋转之后，R
3. 然后再平移回来。T2

T1 = $\begin{bmatrix}
1 & 0 & -Xr \\
0 & 1 & -Yr \\ 0 & 0 & 1
\end{bmatrix}$ R = $\begin{bmatrix} 
cosθ & -sinθ & 0 \\
sinθ & cosθ & 0 \\ 0 & 0 & 1
\end{bmatrix}$ T2 = $\begin{bmatrix}
1 & 0 & -Xr \\
0 & 1 & -Yr \\ 0 & 0 & 1
\end{bmatrix}$ 

 =>P· =  T2 * R * T1 * P =  $\begin{bmatrix}
cosθ  & -sinθ & Xr(1-cosθ) + Yrsinθ \\
sinθ & cosθ & Yr(1-cosθ) - Xrsinθ \\ 0 & 0 & 1
\end{bmatrix}$   * $\begin{bmatrix}
x \\
y \\ 1
\end{bmatrix}$



问题: 矩阵相乘，`M1*M2是否等于 M2*M1????` 如果不相同，那么矩阵变化的顺序不能改变
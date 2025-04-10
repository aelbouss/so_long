#include "so_long.h"

void    ft_cleaner1(t_game *g, t_img *i, char *msg)
{
	clean_2d_arr(g->map);
	clean_2d_arr(g->mc);
    mlx_destroy_image(g->mlx, i->player);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free(g);
	free(i);
	write(2, msg, ft_strlen(msg));
}

void    ft_cleaner2(t_game *g, t_img *i, char *msg)
{
	clean_2d_arr(g->map);
	clean_2d_arr(g->mc);
    mlx_destroy_image(g->mlx, i->player);
    mlx_destroy_image(g->mlx, i->wall);
    mlx_destroy_display(g->mlx);
    free(g->mlx);
    free(g);
	free(i);
	write(2, msg, ft_strlen(msg));
}

void    ft_cleaner3(t_game *g, t_img *i, char *msg)
{
	clean_2d_arr(g->map);
	clean_2d_arr(g->mc);
    mlx_destroy_image(g->mlx, i->player);
    mlx_destroy_image(g->mlx, i->wall);
    mlx_destroy_image(g->mlx, i->exit);
    mlx_destroy_display(g->mlx);
	free(g->mlx);
    free(g);
	free(i);
	write(2, msg, ft_strlen(msg));
}
void    ft_cleaner4(t_game *g, t_img *i, char *msg)
{
	clean_2d_arr(g->map);
	clean_2d_arr(g->mc);
    mlx_destroy_image(g->mlx, i->player);
    mlx_destroy_image(g->mlx, i->wall);
    mlx_destroy_image(g->mlx, i->exit);
    mlx_destroy_image(g->mlx, i->collectible);
	mlx_destroy_display(g->mlx);
	free(g);
	free(i);
	write(2, msg, ft_strlen(msg));
}

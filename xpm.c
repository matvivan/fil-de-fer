/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:41:01 by matvivan          #+#    #+#             */
/*   Updated: 2020/01/12 19:43:29 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char			**like(void)
{
	static char	*like[] = {"15 14 3 1 ",
	"# c #CC4488",
	"# c #1F1F1F",
	"  c None",
	"  ####   ####  ",
	" ###### ###### ",
	"###############",
	"###############",
	"###############",
	"###############",
	"###############",
	" ############# ",
	"  ###########  ",
	"   #########   ",
	"    #######    ",
	"     #####     ",
	"      ###      ",
	"       #       "};

	return (like);
}

char			**bookmark(void)
{
	static char	*xpm[] = {"32 34 4 1 ",
	". c #1F1F1F",
	". c #B5B5B5",
	"  c None",
	"+ c #1F1F1F",
	" ++++++++++++++++++++++++++++++ ", " ++++++++++++++++++++++++++++++ ",
	" ++..........................++ ", " ++..........................++ ",
	" ++..........................++ ", " ++..........................++ ",
	" ++..........................++ ", " ++..........................++ ",
	" ++..........................++ ", " ++..........................++ ",
	" ++..........................++ ", " ++..........................++ ",
	" ++..........................++ ", " ++..........................++ ",
	" ++..........................++ ", " ++..........................++ ",
	" ++..........................++ ", " ++............++............++ ",
	" ++...........++++...........++ ", " ++..........++++++..........++ ",
	" ++.........+++  +++.........++ ", " ++........+++    +++........++ ",
	" ++.......+++      +++.......++ ", " ++......+++        +++......++ ",
	" ++.....+++          +++.....++ ", " ++....+++            +++....++ ",
	" ++...+++              +++...++ ", " ++..+++                +++..++ ",
	" ++.+++                  +++.++ ", " +++++                    +++++ ",
	" ++++                      ++++ ", " +++                        +++ ",
	" ++                          ++ ", " +                            + "};

	return (xpm);
}

char			**text(void)
{
	static char	*txt[] = {"1",
	"Like", "Comment", "Share", "...",
	"4  likes",
	"matvivan", "main reason of this interface",
	"is show that FdF project not difficult",
	"it is easy like instagram post!", "...more",
	"42 weeks ago",
	"ESC    TO EXIT",
	"SCROLL TO ZOOM",
	"ARROWS TO VIEW",
	"WASD   TO MOVE"};

	return (txt);
}

void			xpm_init(struct ptr *desk)
{
	desk->like = like();
	desk->book = bookmark();
	desk->text = text();
}

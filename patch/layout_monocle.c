void
monocle(Monitor *m)
{
	Client *c;

	for (c = m->stack; c && (!ISVISIBLE(c) || c->isfloating); c = c->snext);
	if (c && !c->isfloating) {
		XMoveWindow(dpy, c->win, m->wx, m->wy);
		resize(c, m->wx, m->wy, m->ww - 2 * c->bw, m->wh - 2 * c->bw, 0);
		c = c->snext;
	}
	for (; c; c = c->snext)
		if (!c->isfloating && ISVISIBLE(c))
			XMoveWindow(dpy, c->win, WIDTH(c) * -2, c->y);
}


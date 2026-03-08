const c = @cImport({
    @cInclude("sys/ioctl.h");
    @cInclude("unistd.h");
    @cInclude("stdlib.h");
});

const Window_Dimensions = extern struct {
    tty_width: i32,
    tty_height: i32,
};

export fn get_tty_dimensions() callconv(.c) Window_Dimensions {

    var w = Window_Dimensions{ .tty_width = 80, .tty_height = 24 };
    var win_size: c.struct_winsize = undefined;

    if (c.ioctl(c.STDOUT_FILENO, c.TIOCGWINSZ, &win_size) == 0) {
        if (win_size.ws_col > 0) {
            w.tty_width = @intCast(win_size.ws_col);
            w.tty_height = @intCast(win_size.ws_row);
            return w;
        }
    }

    // getenv returns a "C pointer" ([*c]const u8) which can be null
    const col_ptr = c.getenv("COLUMNS");
    const row_ptr = c.getenv("LINES");

    if (col_ptr != null) w.tty_width = c.atoi(col_ptr);
    if (row_ptr != null) w.tty_height = c.atoi(row_ptr);

    return w;
}
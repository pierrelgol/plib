const std = @import("std");
const mem = std.mem;
const heap = std.heap;
const debug = std.debug;
const testing = std.testing;
const process = std.process;
const log = std.log;
const c = std.c;
const ascii = std.ascii;
const zlib = @cImport({
    @cInclude("plib.h");
});

const log_info = log.info;
const log_warn = log.warn;
const log_err = log.err;

const expect = testing.expect;
const expect_eql = testing.expectEqual;
const expect_err = testing.expectError;
const expect_fmt = testing.expectFmt;
const expect_eql_slc = testing.expectEqualSlices;
const expect_eql_str = testing.expectEqualStrings;
const expect_str_start_with = testing.expectStringStartsWith;
const expect_str_ends_with = testing.expectStringEndsWith;

// ************************************+************************************* //
//                                   Memory                                   //
// ************************************************************************** //

// ************************************+************************************* //
//                                   Memory                                   //
// ************************************************************************** //

test "memory_create : test1" {
    const ptr = zlib.memory_create(1, 8) orelse null;
    defer _ = zlib.memory_destroy(ptr);
    try expect(@TypeOf(ptr) == ?*anyopaque);
}

test "memory_create : test2" {
    const ptr = zlib.memory_create(1, 0);
    defer _ = zlib.memory_destroy(ptr);
    try expect(@TypeOf(ptr) == ?*anyopaque);
    try expect(ptr == null);
}

test "memory_create : test3" {
    for (1..512, 1..512) |count, size| {
        const ptr = zlib.memory_create(count, size) orelse null;
        defer _ = zlib.memory_destroy(ptr);
        try expect(@TypeOf(ptr) == ?*anyopaque);
        try expect(ptr != null);
    }
}

test "memory_destroy : test1" {
    const ptr = zlib.memory_create(1, 8) orelse null;
    const result = zlib.memory_destroy(ptr);
    try expect(@TypeOf(result) == ?*anyopaque);
}

test "memory_destroy : test2" {
    const ptr = zlib.memory_create(1, 0) orelse null;
    const result = zlib.memory_destroy(ptr);
    try expect(@TypeOf(result) == ?*anyopaque);
    try expect(result == null);
}

test "memory_destroy : test3" {
    for (1..512, 1..512) |count, size| {
        const ptr = zlib.memory_create(count, size) orelse null;
        const result = zlib.memory_destroy(ptr);
        try expect(@TypeOf(result) == ?*anyopaque);
        try expect(result == null);
    }
}

test "memory_compare : test1" {
    const str1 = "";
    const str2 = "";
    const result = zlib.memory_compare(str1, str2, 0);
    try expect(result == 0);
}

test "memory_compare : test2" {
    const str1 = @as(?*anyopaque, @constCast(@ptrCast("1")));
    const str2 = @as(?*anyopaque, @constCast(@ptrCast("1")));
    const result = zlib.memory_compare(str1, str2, 1);
    try expect(result == 0);
}

test "memory_compare : test3" {
    const str1 = @as(?*anyopaque, @constCast(@ptrCast("1")));
    const str2 = @as(?*anyopaque, @constCast(@ptrCast("2")));
    const result = zlib.memory_compare(str1, str2, 1);
    try expect(result == -1);
}

test "memory_compare : test4" {
    const str1 = @as(?*anyopaque, @constCast(@ptrCast("2")));
    const str2 = @as(?*anyopaque, @constCast(@ptrCast("1")));
    const result = zlib.memory_compare(str1, str2, 1);
    try expect(result == 1);
}

test "memory_compare : test5" {
    const str1 = @as(?*anyopaque, @constCast(@ptrCast("this" ** 10 ++ "a")));
    const str2 = @as(?*anyopaque, @constCast(@ptrCast("this" ** 10 ++ "b")));
    const result = zlib.memory_compare(str1, str2, 41);
    try expect(result == -1);
}

test "memory_compare : test6" {
    const str1 = @as(?*anyopaque, @constCast(@ptrCast("this" ** 10 ++ "b")));
    const str2 = @as(?*anyopaque, @constCast(@ptrCast("this" ** 10 ++ "a")));
    const result = zlib.memory_compare(str1, str2, 41);
    try expect(result == 1);
}

test "memory_copy : test1" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2: [26]u8 = undefined;

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const ptr2 = @as(?*anyopaque, @constCast((@ptrCast(buff2[0..]))));

    const result = zlib.memory_copy(ptr2, ptr1, buff1.len);

    const slice1: []const u8 = @as([*]u8, @ptrCast(ptr1))[0..buff1.len];
    const slice2: []const u8 = @as([*]u8, @ptrCast(result))[0..buff2.len];

    try expect_eql_slc(u8, slice1, slice2);
}

test "memory_copy : test2" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    var buff2: [26]u8 = undefined;

    for (1..buff1.len) |n| {
        const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
        const ptr2 = @as(?*anyopaque, @constCast((@ptrCast(buff2[0..]))));
        const result = zlib.memory_copy(ptr2, ptr1, @intCast(n));
        const slice1: []const u8 = @as([*]u8, @ptrCast(ptr1))[0..n];
        const slice2: []const u8 = @as([*]u8, @ptrCast(result))[0..n];
        try expect_eql_slc(u8, slice1, slice2);
        @memset(buff2[0..n], 0x00);
    }
}

test "memory_copy : test3" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2: [26]u8 = undefined;

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const ptr2 = @as(?*anyopaque, @constCast((@ptrCast(buff2[0..]))));

    const result = zlib.memory_copy(ptr2, ptr1, 0);
    try expect(result == ptr2);
}

test "memory_move : test1" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2: [26]u8 = undefined;

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const ptr2 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const ptr3 = @as(?*anyopaque, @constCast((@ptrCast(buff2[1..]))));
    _ = zlib.memory_copy(ptr2, ptr1, 0);
    const result = zlib.memory_move(ptr2, ptr3, buff2.len - 1);
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0 .. buff2.len - 1];
    try expect_eql_slc(u8, slice1, "bcdefghijklmnopqrstuvwxyz"[0 .. buff2.len - 1]);
}

test "memory_move : test2" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2: [26]u8 = undefined;

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const ptr2 = @as(?*anyopaque, @constCast((@ptrCast(buff1[1..]))));
    const ptr3 = @as(?*anyopaque, @constCast((@ptrCast(buff2[0..]))));
    _ = zlib.memory_copy(ptr2, ptr1, 0);
    const result = zlib.memory_move(ptr2, ptr3, buff2.len - 1);
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0 .. buff2.len - 1];
    try expect_eql_slc(u8, slice1, "abcdefghijklmnopqrstuvwxy"[0 .. buff2.len - 1]);
}

test "memory_move : test3" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2 = "abcdefghijklmnopqrstuvwxyz";

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const ptr2 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const result = zlib.memory_move(ptr1, ptr2, buff2.len);
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0..buff2.len];
    try expect_eql_slc(u8, slice1, "abcdefghijklmnopqrstuvwxyz"[0..buff2.len]);
}

test "memory_move : test4" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2 = "abcdefghijklmnopqrstuvwxyz";

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const ptr2 = @as(?*anyopaque, @constCast((@ptrCast(buff1[0..]))));
    const result = zlib.memory_move(ptr1, ptr2, @intCast(0));
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0..buff2.len];
    try expect_eql_slc(u8, slice1, "abcdefghijklmnopqrstuvwxyz"[0..buff2.len]);
}

test "memory_realloc : test1" {
    const expected = "Hello, World!";
    const buff = zlib.memory_create(@sizeOf(u8), expected.len + 1);

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(expected[0..]))));
    _ = zlib.memory_copy(buff, ptr1, expected.len);

    const new_buff = zlib.memory_realloc(buff, expected.len, expected.len * 2);
    defer _ = zlib.memory_destroy(new_buff);

    const slice1: []const u8 = @as([*]u8, @ptrCast(new_buff))[0..expected.len];
    try expect_eql_slc(u8, slice1[0..], expected[0..]);
}

test "memory_realloc : test2" {
    const expected = "H";
    const buff = zlib.memory_create(@sizeOf(u8), expected.len + 1);

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(expected[0..]))));
    _ = zlib.memory_copy(buff, ptr1, expected.len);

    const new_buff = zlib.memory_realloc(buff, expected.len, expected.len * 2);
    defer _ = zlib.memory_destroy(new_buff);

    const slice1: []const u8 = @as([*]u8, @ptrCast(new_buff))[0..expected.len];
    try expect_eql_slc(u8, slice1[0..], expected[0..]);
}

test "memory_realloc : test3" {
    const expected = "";
    const buff = zlib.memory_create(@sizeOf(u8), expected.len + 1);

    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(expected[0..]))));
    _ = zlib.memory_copy(buff, ptr1, expected.len);

    const new_buff = zlib.memory_realloc(buff, expected.len, expected.len * 2);
    defer _ = zlib.memory_destroy(new_buff);

    const slice1: []const u8 = @as([*]u8, @ptrCast(new_buff))[0..expected.len];
    try expect_eql_slc(u8, slice1[0..], expected[0..]);
}

test "memory_realloc : test4" {
    const expected = "Hello, World!";
    const buff = zlib.memory_create(@sizeOf(u8), expected.len + 1);
    const ptr1 = @as(?*anyopaque, @constCast((@ptrCast(expected[0..]))));
    _ = zlib.memory_copy(buff, ptr1, expected.len);
    const new_buff = zlib.memory_realloc(buff, expected.len, expected.len + 1);
    defer _ = zlib.memory_destroy(new_buff);
    const slice1: []const u8 = @as([*]u8, @ptrCast(new_buff))[0..expected.len];
    try expect_eql_slc(u8, slice1[0..], expected[0..]);
}

test "memory_set : test1" {
    var expected: [32]u8 = undefined;
    @memset(expected[0..], 0);
    const mem1: [32]u8 = undefined;
    _ = zlib.memory_set(@as(?*anyopaque, @constCast(@ptrCast(mem1[0..]))), 0x00, mem1.len);
    try expect_eql_slc(u8, mem1[0..], expected[0..]);
}

test "memory_set : test2" {
    var expected: [32]u8 = undefined;
    @memset(expected[0..], 0xaa);
    const mem1: [32]u8 = undefined;
    _ = zlib.memory_set(@as(?*anyopaque, @constCast(@ptrCast(mem1[0..]))), 0xaa, mem1.len);
    try expect_eql_slc(u8, mem1[0..], expected[0..]);
}

test "memory_set : test3" {
    var expected: [32]u8 = undefined;
    const mem1: [32]u8 = undefined;
    _ = zlib.memory_set(@as(?*anyopaque, @constCast(@ptrCast(mem1[0..]))), 0xaa, 0);
    try expect_eql_slc(u8, mem1[0..], expected[0..]);
}

// ************************************+************************************* //
//                                    Char                                    //
// ************************************************************************** //

test "char_is_alnum : test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_alnum(ch) >= 1) true else (false);
        try expect(res == ascii.isAlphanumeric(ch));
    }
}

test "char_is_alpha : test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_alpha(ch) >= 1) true else (false);
        try expect(res == ascii.isAlphabetic(ch));
    }
}

test "char_is_digit: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_digit(ch) >= 1) true else (false);
        try expect(res == ascii.isDigit(ch));
    }
}

test "char_is_space: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_spaces(ch) >= 1) true else (false);
        try expect(res == ascii.isWhitespace(ch));
    }
}

test "char_is_lowercase: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_lowercase(ch) >= 1) true else (false);
        try expect(res == ascii.isLower(ch));
    }
}

test "char_is_uppercase: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_uppercase(ch) >= 1) true else (false);
        try expect(res == ascii.isUpper(ch));
    }
}

test "char_is_even: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_even(ch) >= 1) true else (false);
        try expect(res == if (i % 2 == 0) true else false);
    }
}

test "char_is_odd: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_odd(ch) >= 1) true else (false);
        try expect(res == if (i % 2 != 0) true else false);
    }
}

test "char_is_printable: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_printable(ch) >= 1) true else (false);
        try expect(res == ascii.isPrint(ch));
    }
}

test "char_is_ascii: test1" {
    for (0..255) |i| {
        const ch: u8 = @truncate(i);
        const res: bool = if (zlib.char_is_ascii(ch) >= 1) true else (false);
        try expect(res == ascii.isASCII(ch));
    }
}

test "char_is_binary: test1" {
    for (0..255) |i| {
        switch (i) {
            '0', '1' => try expect((if (zlib.char_is_binary(@intCast(i)) == 1) true else false) == true),
            else => try expect((if (zlib.char_is_binary(@intCast(i)) == 1) true else false) == false),
        }
    }
}

test "char_is_hex: test1" {
    for (0..255) |i| {
        switch (i) {
            '0'...'9' => try expect((if (zlib.char_is_hex(@intCast(i)) == 1) true else false) == true),
            'A'...'F' => try expect((if (zlib.char_is_hex(@intCast(i)) == 1) true else false) == true),
            'a'...'f' => try expect((if (zlib.char_is_hex(@intCast(i)) == 1) true else false) == true),
            else => try expect((if (zlib.char_is_hex(@intCast(i)) == 1) true else false) == false),
        }
    }
}

test "char_is_newline: test1" {
    const new_line: u8 = '\n';
    const result: bool = if (zlib.char_is_newline(new_line) >= 1) true else false;
    try expect(result == true);
}

// ************************************+************************************* //
//                                   String                                   //
// ************************************************************************** //

test "string_clone : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "This is a string";
    const ptr = zlib.string_clone(heapalloc, @constCast(@ptrCast(expected)));
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_clone : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "";
    const ptr = zlib.string_clone(heapalloc, @constCast(@ptrCast(expected)));
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_clone : test3" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "0";
    const ptr = zlib.string_clone(heapalloc, @constCast(@ptrCast(expected)));
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_compare : test1" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const result = zlib.string_compare(str1, str2);
    try expect(result == 0);
}

test "string_compare : test2" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a testa"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a testb"));
    const result = zlib.string_compare(str1, str2);
    try expect(result == -1);
}

test "string_compare : test3" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a testb"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a testa"));
    const result = zlib.string_compare(str1, str2);
    try expect(result == 1);
}

test "string_compare : test4" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is b"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const result = zlib.string_compare(str1, str2);
    try expect(result == 1);
}

test "string_compare : test5" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is b"));
    const result = zlib.string_compare(str1, str2);
    try expect(result == -1);
}

test "string_concat : test1" {
    const str1 = "Hello, ";
    const str2 = "World!";
    var buffer: [16]u8 = undefined;
    @memset(buffer[0..], 0x00);
    var ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str1[0..])), str1.len);
    ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str2[0..])), str2.len);
    try expect_eql_str("Hello, World!", mem.span(ptr));
}

test "string_concat : test2" {
    const str1 = "";
    const str2 = "";
    var buffer: [16]u8 = undefined;
    @memset(buffer[0..], 0x00);
    var ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str1[0..])), str1.len);
    ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str2[0..])), str2.len);
    try expect_eql_str("", mem.span(ptr));
}

test "string_concat : test3" {
    const str1 = "a";
    const str2 = "";
    var buffer: [16]u8 = undefined;
    @memset(buffer[0..], 0x00);
    var ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str1[0..])), str1.len);
    ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str2[0..])), str2.len);
    try expect_eql_str("a", mem.span(ptr));
}

test "string_concat : test4" {
    const str1 = "";
    const str2 = "a";
    var buffer: [16]u8 = undefined;
    @memset(buffer[0..], 0x00);
    var ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str1[0..])), str1.len);
    ptr = zlib.string_concat(@ptrCast(buffer[0..]), @constCast(@ptrCast(str2[0..])), str2.len);
    try expect_eql_str("a", mem.span(ptr));
}

test "string_copy : test1" {
    const str1 = "Hello, World!";
    var buffer: [16]u8 = undefined;
    @memset(buffer[0..], 0x00);
    const ptr = zlib.string_copy(@ptrCast(buffer[0..]), @constCast(@ptrCast(str1[0..])), str1.len);
    try expect_eql_str("Hello, World!", mem.span(ptr));
}

test "string_copy : test2" {
    const str1 = "";
    var buffer: [16]u8 = undefined;
    @memset(buffer[0..], 0x00);
    const ptr = zlib.string_copy(@ptrCast(buffer[0..]), @constCast(@ptrCast(str1[0..])), str1.len);
    try expect_eql_str("", mem.span(ptr));
}

test "string_copy : test3" {
    const str1 = "a";
    var buffer: [16]u8 = undefined;
    @memset(buffer[0..], 0x00);
    const ptr = zlib.string_copy(@ptrCast(buffer[0..]), @constCast(@ptrCast(str1[0..])), str1.len);
    try expect_eql_str("a", mem.span(ptr));
}

test "string_count : test1" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 3);
}

test "string_count : test2" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count(@constCast(@ptrCast(str1)), 'b');
    try expect(result == 3);
}

test "string_count : test3" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count(@constCast(@ptrCast(str1)), 'c');
    try expect(result == 3);
}

test "string_count : test4" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count(@constCast(@ptrCast(str1)), 'z');
    try expect(result == 0);
}

test "string_count : test5" {
    const str1 = "aaa" ** 10;
    const result = zlib.string_count(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 30);
}

test "string_count_leading : test1" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_leading(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 3);
}

test "string_count_leading : test2" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_leading(@constCast(@ptrCast(str1)), 'b');
    try expect(result == 0);
}

test "string_count_leading : test3" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_leading(@constCast(@ptrCast(str1)), 'c');
    try expect(result == 0);
}

test "string_count_leading : test4" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_leading(@constCast(@ptrCast(str1)), 'z');
    try expect(result == 0);
}

test "string_count_leading : test5" {
    const str1 = "aaa" ** 10;
    const result = zlib.string_count_leading(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 30);
}

test "string_count_trailing : test1" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_trailing(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 0);
}

test "string_count_trailing : test2" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_trailing(@constCast(@ptrCast(str1)), 'b');
    try expect(result == 0);
}

test "string_count_trailing : test3" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_trailing(@constCast(@ptrCast(str1)), 'c');
    try expect(result == 3);
}

test "string_count_trailing : test4" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_trailing(@constCast(@ptrCast(str1)), 'z');
    try expect(result == 0);
}

test "string_count_trailing : test5" {
    const str1 = "aaa" ** 10;
    const result = zlib.string_count_trailing(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 30);
}

test "string_count_until : test1" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_until(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 0);
}

test "string_count_until : test2" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_until(@constCast(@ptrCast(str1)), 'b');
    try expect(result == 4);
}

test "string_count_until : test3" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_until(@constCast(@ptrCast(str1)), 'c');
    try expect(result == 8);
}

test "string_count_until : test4" {
    const str1 = "aaa_bbb_ccc";
    const result = zlib.string_count_until(@constCast(@ptrCast(str1)), 'z');
    try expect(result == str1.len);
}

test "string_count_until : test5" {
    const str1 = "aaa" ** 10;
    const result = zlib.string_count_until(@constCast(@ptrCast(str1)), 'a');
    try expect(result == 0);
}

test "string_create : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "This is a string";
    var ptr = zlib.string_create(heapalloc, expected.len + 1);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    ptr = zlib.string_copy(ptr, @ptrCast(expected), expected.len);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_create : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "";
    var ptr = zlib.string_create(heapalloc, expected.len + 1);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    ptr = zlib.string_copy(ptr, @ptrCast(expected), expected.len);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_destroy : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "This is a string";
    var ptr = zlib.string_create(heapalloc, expected.len + 1);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    ptr = zlib.string_copy(ptr, @ptrCast(expected), expected.len);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_destroy : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);
    const expected = "";
    var ptr = zlib.string_create(heapalloc, expected.len + 1);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    ptr = zlib.string_copy(ptr, @ptrCast(expected), expected.len);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_join : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);
    const str1: [*c]u8 = @constCast(@ptrCast("Hello, "));
    const str2: [*c]u8 = @constCast(@ptrCast("World!"));
    const result = zlib.string_join(heapalloc, str1, str2);
    defer _ = zlib.heap_destroy(heapalloc, result);
    try expect_eql_str("Hello, World!", mem.span(result));
}

test "string_join : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);
    const str1: [*c]u8 = @constCast(@ptrCast(""));
    const str2: [*c]u8 = @constCast(@ptrCast(""));
    const result = zlib.string_join(heapalloc, str1, str2);
    defer _ = zlib.heap_destroy(heapalloc, result);
    try expect_eql_str("", mem.span(result));
}

test "string_join : test3" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);
    const str1: [*c]u8 = @constCast(@ptrCast("a"));
    const str2: [*c]u8 = @constCast(@ptrCast("b"));
    const result = zlib.string_join(heapalloc, str1, str2);
    defer _ = zlib.heap_destroy(heapalloc, result);
    try expect_eql_str("ab", mem.span(result));
}

test "string_join : test4" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);
    const str1: [*c]u8 = @constCast(@ptrCast(""));
    const str2: [*c]u8 = @constCast(@ptrCast("b"));
    const result = zlib.string_join(heapalloc, str1, str2);
    defer _ = zlib.heap_destroy(heapalloc, result);
    try expect_eql_str("b", mem.span(result));
}

test "string_join : test5" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);
    const str1: [*c]u8 = @constCast(@ptrCast("a"));
    const str2: [*c]u8 = @constCast(@ptrCast(""));
    const result = zlib.string_join(heapalloc, str1, str2);
    defer _ = zlib.heap_destroy(heapalloc, result);
    try expect_eql_str("a", mem.span(result));
}

test "string_length : test1" {
    const str = "This is a test";
    const result = zlib.string_length(@constCast(@ptrCast(str)));
    try expect(result == str.len);
}

test "string_length : test2" {
    const str = "This is a test" ** 100;
    const result = zlib.string_length(@constCast(@ptrCast(str)));
    try expect(result == str.len);
}

test "string_length : test3" {
    const str = "";
    const result = zlib.string_length(@constCast(@ptrCast(str)));
    try expect(result == str.len);
}

test "string_move : test1" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2: [26]u8 = undefined;

    const ptr1: [*c]u8 = @constCast(@ptrCast(buff1[0..]));
    const ptr2: [*c]u8 = @constCast(@ptrCast(buff1[0..]));
    const ptr3: [*c]u8 = @constCast(@ptrCast(buff2[1..]));
    _ = zlib.memory_copy(ptr2, ptr1, 0);
    const result = zlib.string_move(ptr2, ptr3, buff2.len - 1);
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0 .. buff2.len - 1];
    try expect_eql_slc(u8, slice1, "bcdefghijklmnopqrstuvwxyz"[0 .. buff2.len - 1]);
}

test "string_move : test2" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2: [26]u8 = undefined;

    const ptr1: [*c]u8 = @constCast(@ptrCast(buff1[0..]));
    const ptr2: [*c]u8 = @constCast(@ptrCast(buff1[1..]));
    const ptr3: [*c]u8 = @constCast(@ptrCast(buff2[0..]));
    _ = zlib.string_copy(ptr2, ptr1, 0);
    const result = zlib.string_move(ptr2, ptr3, buff2.len - 1);
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0 .. buff2.len - 1];
    try expect_eql_slc(u8, slice1, "abcdefghijklmnopqrstuvwxy"[0 .. buff2.len - 1]);
}

test "string_move : test3" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2 = "abcdefghijklmnopqrstuvwxyz";

    const ptr1: [*c]u8 = @constCast(@ptrCast(buff1[0..]));
    const ptr2: [*c]u8 = @constCast(@ptrCast(buff1[1..]));
    const result = zlib.string_move(ptr1, ptr2, buff2.len);
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0..buff2.len];
    try expect_eql_slc(u8, slice1, "abcdefghijklmnopqrstuvwxyz"[0..buff2.len]);
}

test "string_move : test4" {
    const buff1 = "abcdefghijklmnopqrstuvwxyz";
    const buff2 = "abcdefghijklmnopqrstuvwxyz";

    const ptr1: [*c]u8 = @constCast(@ptrCast(buff1[0..]));
    const ptr2: [*c]u8 = @constCast(@ptrCast(buff1[1..]));
    const result = zlib.string_move(ptr1, ptr2, @intCast(0));
    const slice1: []const u8 = @as([*]u8, @ptrCast(result))[0..buff2.len];
    try expect_eql_slc(u8, slice1, "abcdefghijklmnopqrstuvwxyz"[0..buff2.len]);
}

test "string_nclone : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "This is a string";
    const ptr = zlib.string_nclone(heapalloc, @constCast(@ptrCast(expected)), expected.len);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_nclone : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "";
    const ptr = zlib.string_nclone(heapalloc, @constCast(@ptrCast(expected)), expected.len);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_nclone : test3" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const expected = "0";
    const ptr = zlib.string_nclone(heapalloc, @constCast(@ptrCast(expected)), expected.len);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str(expected, mem.span(ptr));
}

test "string_ncompare : test1" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const result = zlib.string_ncompare(str1, str2, 14);
    try expect(result == 0);
}

test "string_ncompare : test2" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a testa"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a testb"));
    const result = zlib.string_ncompare(str1, str2, 14);
    try expect(result == -1);
}

test "string_ncompare : test3" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a testb"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a testa"));
    const result = zlib.string_ncompare(str1, str2, 14);
    try expect(result == 1);
}

test "string_ncompare : test4" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is b"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const result = zlib.string_ncompare(str1, str2, 14);
    try expect(result == 1);
}

test "string_ncompare : test5" {
    const str1: [*c]u8 = @constCast(@ptrCast("This is a test"));
    const str2: [*c]u8 = @constCast(@ptrCast("This is b"));
    const result = zlib.string_ncompare(str1, str2, 14);
    try expect(result == -1);
}

test "string_pad : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const str1 = "a" ** 5;
    const ptr = zlib.string_pad(heapalloc, @constCast(@ptrCast(str1)), 'b', 5);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str("bbbbbaaaaabbbbb", mem.span(ptr));
}

test "string_pad : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const str1 = "a" ** 5;
    const ptr = zlib.string_pad(heapalloc, @constCast(@ptrCast(str1)), 'b', 0);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str(str1, mem.span(ptr));
}

test "string_pad : test3" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    const str1 = "a" ** 5;
    const ptr = zlib.string_pad(heapalloc, @constCast(@ptrCast(str1)), 'b', 1);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str("b" ++ "a" ** 5 ++ "b", mem.span(ptr));
}

test "string_reverse : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    var ptr = zlib.string_clone(heapalloc, "abcdefhijklmnopqrstuvwxyz");
    ptr = zlib.string_reverse(@constCast(@ptrCast(ptr)));
    defer _ = zlib.heap_destroy(heapalloc, ptr);

    try expect_eql_str("zyxwvutsrqponmlkjihfedcba", mem.span(ptr));
}

test "string_reverse : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    var ptr = zlib.string_clone(heapalloc, "ab");
    ptr = zlib.string_reverse(@constCast(@ptrCast(ptr)));
    defer _ = zlib.heap_destroy(heapalloc, ptr);

    try expect_eql_str("ba", mem.span(ptr));
}

test "string_reverse : test3" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    var ptr = zlib.string_clone(heapalloc, "");
    ptr = zlib.string_reverse(@constCast(@ptrCast(ptr)));
    defer _ = zlib.heap_destroy(heapalloc, ptr);

    try expect_eql_str("", mem.span(ptr));
}

test "string_rotate : test1" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    var ptr = zlib.string_clone(heapalloc, @constCast(@ptrCast("abc")));
    ptr = zlib.string_rotate(heapalloc, ptr, 1);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str("cab", mem.span(ptr));
}

test "string_rotate : test2" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    var ptr = zlib.string_clone(heapalloc, "abc");
    ptr = zlib.string_rotate(heapalloc, ptr, -1);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str("bca", mem.span(ptr));
}

test "string_rotate : test3" {
    const heapalloc = zlib.heap_init();
    defer _ = zlib.heap_deinit(heapalloc);

    var ptr = zlib.string_clone(heapalloc, "abc");
    ptr = zlib.string_rotate(heapalloc, ptr, 0);
    defer _ = zlib.heap_destroy(heapalloc, ptr);
    try expect_eql_str("abc", mem.span(ptr));
}

test "string_search : test1" {
    const haystack = "This is a very long string who's purpose is to see if we can find a needle";
    const needle = "needle";

    const ptr1 = zlib.string_search(@constCast(@ptrCast(haystack)), @constCast(@ptrCast(needle)), haystack.len, needle.len);

    try expect_eql_str(mem.span(ptr1), "needle");
}

test "string_search : test2" {
    const haystack = "This is a very long string who's purpose is to see if we can find a needle";
    const needle = "This";

    const ptr1 = zlib.string_search(@constCast(@ptrCast(haystack)), @constCast(@ptrCast(needle)), haystack.len, needle.len);

    try expect_eql_str(mem.span(ptr1), haystack);
}

test "string_search : test3" {
    const haystack = "";
    const needle = "";

    const ptr1 = zlib.string_search(@constCast(@ptrCast(haystack)), @constCast(@ptrCast(needle)), haystack.len, needle.len);

    try expect_eql_str(mem.span(ptr1), haystack);
}

test "string_set : test1" {
    var buffer1: [32]u8 = undefined;
    var buffer2: [32]u8 = undefined;

    @memset(buffer1[0..], 0x00);
    _ = zlib.string_set(@ptrCast(buffer2[0..]), 0x00, 32);
    try expect_eql_slc(u8, buffer1[0..], buffer2[0..]);
}

const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const plib = b.addStaticLibrary(.{
        .name = "plib",
        .target = target,
        .optimize = optimize,
    });
    plib.linkLibC();
    plib.addIncludePath(.{ .path = "include/" });
    plib.addCSourceFiles(.{ .files = &C_SOURCE_FILES, .flags = &.{
        "-Wall",
        "-Werror",
        "-Wextra",
    } });
    b.installArtifact(plib);

    const main_tests = b.addTest(.{
        .root_source_file = .{ .path = "test/test.zig" },
        .target = target,
        .optimize = optimize,
    });
    main_tests.addIncludePath(.{ .path = "include/" });
    main_tests.linkLibrary(plib);
    main_tests.linkLibC();

    const run_main_tests = b.addRunArtifact(main_tests);
    const test_step = b.step("test", "Run library tests");
    test_step.dependOn(&run_main_tests.step);
}

const C_SOURCE_FILES = [_][]const u8{
    "src/allocator/arena_create.c",
    "src/allocator/arena_deinit.c",
    "src/allocator/arena_destroy.c",
    "src/allocator/arena_init.c",
    "src/allocator/arena_realloc.c",
    "src/allocator/heap_create.c",
    "src/allocator/heap_deinit.c",
    "src/allocator/heap_destroy.c",
    "src/allocator/heap_init.c",
    "src/allocator/heap_realloc.c",
    "src/bit/bit_bitmask_combine.c",
    "src/bit/bit_bitmask_create.c",
    "src/bit/bit_check_parity.c",
    "src/bit/bit_compare_bits.c",
    "src/bit/bit_count_set_bits.c",
    "src/bit/bit_count_unset_bits.c",
    "src/bit/bit_is_set.c",
    "src/bit/bit_reverse_bits.c",
    "src/bit/bit_rotate_left.c",
    "src/bit/bit_rotate_right.c",
    "src/bit/bit_set_bit.c",
    "src/bit/bit_swap_bits.c",
    "src/bit/bit_toggle_bit.c",
    "src/bit/bit_unset_bit.c",
    "src/buffer/buffer_create.c",
    "src/buffer/buffer_destroy.c",
    "src/buffer/buffer_growth.c",
    "src/buffer/buffer_peek.c",
    "src/buffer/buffer_ptr.c",
    "src/buffer/buffer_read.c",
    "src/buffer/buffer_reset.c",
    "src/buffer/buffer_should_grow.c",
    "src/buffer/buffer_unread.c",
    "src/buffer/buffer_write.c",
    "src/char/char_is_alnum.c",
    "src/char/char_is_alpha.c",
    "src/char/char_is_ascii.c",
    "src/char/char_is_binary.c",
    "src/char/char_is_decimal.c",
    "src/char/char_is_digit.c",
    "src/char/char_is_even.c",
    "src/char/char_is_hex.c",
    "src/char/char_is_lowercase.c",
    "src/char/char_is_newline.c",
    "src/char/char_is_octal.c",
    "src/char/char_is_odd.c",
    "src/char/char_is_printable.c",
    "src/char/char_is_spaces.c",
    "src/char/char_is_uppercase.c",
    "src/char/char_is_whitespace.c",
    "src/char/char_to_lowercase.c",
    "src/char/char_to_reversecase.c",
    "src/char/char_to_uppercase.c",
    "src/file/file_buffer_create.c",
    "src/file/file_buffer_destroy.c",
    "src/file/file_buffer_load_chunck.c",
    "src/file/file_buffer_read.c",
    "src/file/file_clone_name.c",
    "src/file/file_clone_path.c",
    "src/file/file_close.c",
    "src/file/file_create.c",
    "src/file/file_destroy.c",
    "src/file/file_open.c",
    "src/file/file_read.c",
    "src/file/file_size.c",
    "src/file/file_write.c",
    "src/list/list_clear.c",
    "src/list/list_clone.c",
    "src/list/list_concat.c",
    "src/list/list_create.c",
    "src/list/list_destroy.c",
    "src/list/list_insert_at.c",
    "src/list/list_length.c",
    "src/list/list_peek_at.c",
    "src/list/list_pop_at.c",
    "src/list/list_push_at.c",
    "src/list/list_remove_at.c",
    "src/list/list_rotate.c",
    "src/list/list_sort.c",
    "src/list/list_split_at.c",
    "src/memory/memory_search.c",
    "src/memory/memory_create.c",
    "src/memory/memory_destroy.c",
    "src/memory/memory_compare.c",
    "src/memory/memory_realloc.c",
    "src/memory/memory_copy.c",
    "src/memory/memory_move.c",
    "src/memory/memory_set.c",
    "src/print/fsm.c",
    "src/print/print_fmt.c",
    "src/print/print_fmt_i32.c",
    "src/print/print_fmt_i8.c",
    "src/print/print_fmt_lhex.c",
    "src/print/print_fmt_ptr.c",
    "src/print/print_fmt_str.c",
    "src/print/print_fmt_u32.c",
    "src/print/print_fmt_uhex.c",
    "src/print/print_string.c",
    "src/print/print_string_nl.c",
    "src/print/putnbr_base.c",
    "src/split/split.c",
    "src/split/split_clone.c",
    "src/split/split_compare.c",
    "src/split/split_create.c",
    "src/split/split_destroy.c",
    "src/split/split_length.c",
    "src/split/split_line.c",
    "src/split/split_nsplit.c",
    "src/split/split_reverse.c",
    "src/split/split_search.c",
    "src/split/split_size.c",
    "src/split/split_sort.c",
    "src/split/split_unsplit.c",
    "src/split/split_whitespace.c",
    "src/stack/stack_clear.c",
    "src/stack/stack_create.c",
    "src/stack/stack_destroy.c",
    "src/stack/stack_grow.c",
    "src/stack/stack_is_empty.c",
    "src/stack/stack_is_full.c",
    "src/stack/stack_length.c",
    "src/stack/stack_peek.c",
    "src/stack/stack_pop.c",
    "src/stack/stack_push.c",
    "src/stack/stack_rotate.c",
    "src/stack/stack_shrink.c",
    "src/string/string_clone.c",
    "src/string/string_nclone.c",
    "src/string/string_compare.c",
    "src/string/string_concat.c",
    "src/string/string_copy.c",
    "src/string/string_count.c",
    "src/string/string_count_until.c",
    "src/string/string_count_leading.c",
    "src/string/string_count_trailing.c",
    "src/string/string_create.c",
    "src/string/string_destroy.c",
    "src/string/string_join.c",
    "src/string/string_length.c",
    "src/string/string_move.c",
    "src/string/string_ncompare.c",
    "src/string/string_pad.c",
    "src/string/string_reverse.c",
    "src/string/string_rotate.c",
    "src/string/string_search.c",
    "src/string/string_set.c",
    "src/string/string_slice.c",
    "src/string/string_sort.c",
    "src/string/string_to_long.c",
    "src/string/string_trim.c",
    "src/table/table_body_create.c",
    "src/table/table_body_find_empty.c",
    "src/table/table_body_remove.c",
    "src/table/table_body_resize.c",
    "src/table/table_create.c",
    "src/table/table_destroy.c",
    "src/table/table_entry_get.c",
    "src/table/table_entry_set.c",
    "src/table/table_hash.c",
};

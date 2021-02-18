#pragma once

enum class CheckInOrOutResult
{
    Success,
    BookNotFound,
    Failure,
    AlreadyCheckedOut,
    AlreadyCheckedIn
};
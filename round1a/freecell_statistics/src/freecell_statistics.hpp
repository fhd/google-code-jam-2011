inline bool is_possible(long max_games_today, long won_today, long won_total)
{
    if (won_total == 100 && won_today < 100)
        return false;

    if (won_total == 0 && won_today > 0)
        return false;

    for (long games_today = 1; games_today <= max_games_today; games_today++)
        if (100 % games_today == 0 && won_today % (100 / games_today) == 0)
            return true;

    return false;
}

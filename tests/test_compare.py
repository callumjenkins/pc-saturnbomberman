from saturnrecomp import audio

from bomberman import compare


def test_neighbouring_odd_parts_of_one_window_make_one_stretch_at_their_loudest():
    part = lambda start, level, level_ref: audio.Part(start, 0.1, level, level_ref)
    odd = [(6300, part(7 * audio.PART, 0.04, 0.001)), (6300, part(8 * audio.PART, 0.02, 0.0)),
           (6300, part(11 * audio.PART, 0.03, 0.0)), (6360, part(12 * audio.PART, 0.05, 0.0))]
    assert compare.stretches(odd) == [(6300, 7 * audio.PART, 2 * audio.PART, 0.04, 0.001),
                                      (6300, 11 * audio.PART, audio.PART, 0.03, 0.0),
                                      (6360, 12 * audio.PART, audio.PART, 0.05, 0.0)]
